#include <iostream>
#include <iomanip>
#include "Blatt3Aufgabe4.h"

// Naive: just multiply n times
double pow_naive(double x, int n)
{
	double ans = 1;
	for (; n>0; n--) {
		ans *= x;
	}
	return ans;
}

// Recursively double and add
double pow_double_and_add(double x, int n)
{
	if (n == 0) {
		return 1;
	} else if (n%2) {
		return x*pow_double_and_add(x*x, n/2);
	} else {
		return pow_double_and_add(x*x, n/2);
	}
}

// Iteratively double and add, long version
double pow_iterative_ausgeschrieben(double x, int n)
{
	double ans = 1;
	while (n > 0) {
		if (n%2 == 0) {		// gerade
			x *= x;
			n /= 2;
		} else {		// ungerade
			ans *= x;
			x *= x;
			n /= 2;
		}
	}

	return ans;
}

// Iteratively double and add
double pow_iterative(double x, int n)
{
	double ans = 1;
	for (; n > 0; x*=x, n/= 2)
		if (n%2) ans *= x;
	return ans;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		std::cerr << "Error: Not enough input." << std::endl;
		return 1;
	}
	double x = atof(argv[1]);
	int n = atoi(argv[2]);

	std::cout << std::setprecision(16) << "Recursive: " << pow_double_and_add(x, n) << std::endl;
	std::cout << std::setprecision(16) << "Iterative: " << pow_iterative(x, n) << std::endl;
	std::cout << std::setprecision(16) << "Naive:    " << pow_naive(x, n) << std::endl;

	return 0;
}
