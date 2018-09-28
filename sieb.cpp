#include <iostream>
#include <vector>

#define	TRUE	0
#define	FALSE	1

long sieve(int n)
{
	long number_of_primes = 0;
	std::vector<int> is_prime(n-1, TRUE);

	for (int i=2; i<=n; ++i) {
		if (is_prime[i-2] == TRUE) {
			number_of_primes++;
//			std::cout << i << std::endl;
			for (int j=2*i; j <= n; j+=i) {
				is_prime[j-2] = FALSE;
			}
		}
	}

	return number_of_primes;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: no argument." << std::endl;
		return 1;
	}

	int n = atoi(argv[1]);
	std::cout << sieve(n) << std::endl;

	return 0;
}
