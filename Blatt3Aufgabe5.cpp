#include <iostream>
#include <vector>

// Naive recursive binomial coefficients
long long bin(int n, int k)
{
	if (k > n) {
		return 0;
	} else if ((k == 0) or (k == n)) {
		return 1;
	} else {
		return bin(n-1,k-1) + bin(n-1,k);
	}
}

// Naive
long long bell_recursive(int n)
{
	if (n == 0) return 1;

	long long sum = 0;
	for (int k=0; k<n; ++k) {
		sum += bin(n-1, k) * bell_recursive(k);
	}
	return sum;
}

long long bell_iterative(int n)
{
	// Speichere vorherige Bell-Zahlen, zuerst nur B_0
	std::vector<long long> bell = {1};
	// Speichere das Pascalsche Dreieck, zuerst nur (0 0)
	std::vector<std::vector<long long>> binom = {{1}};

	// Berechne B_i fuer alle i.
	for (int i=1; i<=n; ++i) {
		long long b = 0;				// current B_i
		for (int k=0; k<i; ++k) {
			b += binom[i-1][k] * bell[k];
		}
		bell.push_back(b);
		// Update Pascals triangle with (i j) for all 0 <= j <= i
		binom.push_back({1});
		for (int j=1; j<=i; ++j) {
			binom[i].push_back(binom[i-1][j-1] + ((j>=i)?0:binom[i-1][j]));
		}
	}

	return bell[n];
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " r|i n\n";
		return 1;
	}

	char c = argv[1][0];
	int n = atoi(argv[2]);
	if (c == 'r') {
		std::cout << "Rekursiv: " << bell_recursive(n) << std::endl;
	} else if (c == 'i') {
		std::cout << "Iterativ: " << bell_iterative(n) << std::endl;
	} else {
		std::cerr << "HMm.\n";
		return 1;
	}

	return 0;
}
