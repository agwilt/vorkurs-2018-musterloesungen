#include <iostream>

int gcd(int a, int b)
{
	if (a == 0) {
		return b;
	}
	while (b != 0) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

int main(int argc, char *argv[])
{
	int a, b;
	std::cout << "Input a: ";
	std::cin >> a;
	std::cout << "Input b: ";
	std::cin >> b;
	std::cout << std::endl;

	std::cout << "Der GGT ist " << gcd(a, b) << "." << std::endl;
	return 0;
}
