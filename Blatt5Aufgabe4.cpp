#include <iostream>
#include <vector>

void all_primes(int n)
{
	std::vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i=2; i<=n; ++i) {
		if (is_prime[i]) {
			std::cout << i << std::endl;
			// multiples aren't prime:
			for (int j=2*i; j<=n; j+=i) {
				is_prime[j] = false;
			}
		}
	}
}

bool is_prime(int n)
{
	for (int i=2; i*i<=n; ++i)
		if (n%i == 0)
			return false;
	return true;
}

void slow_primes(int n)
{
	for (int i=2; i<=n; ++i)
		if (is_prime(i))
			std::cout << i << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " slow|fast n" << std::endl;
		return 1;
	}

	int n = atoi(argv[2]);
	if (argv[1][0] == 's') {
		slow_primes(n);
	} else if (argv[1][0] == 'f') {
		all_primes(n);
	} else {
		std::cerr << "Invalid speed: " << argv[1] << std::endl;
		return 1;
	}

	return 0;
}
