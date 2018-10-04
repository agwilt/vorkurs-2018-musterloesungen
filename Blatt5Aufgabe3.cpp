#include <iostream>
#include <iomanip>
#include <limits>
//#include <cmath>
#include "Blatt4Aufgabe2.hpp"

double zeta(double s)
{
	if (s <= 1)
		return std::numeric_limits<double>::infinity();
	double sum = 0;
	double summand = 1;
	for (unsigned k=1; summand > __DBL_EPSILON__ and k<10e8; ++k) {
		summand = 1/power(k, s);
		sum += summand;
	}

	return sum;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: No input.\n";
		return 1;
	}

	std::cout << std::setprecision(16) << zeta(atof(argv[1])) << std::endl;

	return 0;
}
