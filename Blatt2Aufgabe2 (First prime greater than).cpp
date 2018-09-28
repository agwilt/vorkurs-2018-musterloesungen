#include <iostream>

bool is_prime(int n)
{
	for (int i=2; i*i<=n; ++i) {
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

int next_prime_after(int n)
{
	while (not is_prime(n)) {
		n++;
	}
	return n;
}

int main(int argc, char *argv[])
{
	int n;
	std::cout << "Bitte Zahl eingeben: ";
	std::cin >> n;
	std::cout << "Die kleinste Primzahl nach " << n << " ist " << next_prime_after(n) << "." << std::endl;

	return 0;
}
