#include <iostream>
#include <iomanip>

double expo(double x)
{
	// Weil die Methode fuer x<<0 ziemlich kaputt ist.
	if (x < 0)
		return 1/expo(-x);
	double summand = 1;
	double sum = summand;
	for (int k=1;
	     summand > __DBL_EPSILON__ or summand < -__DBL_EPSILON__; ++k) {
		summand *= x;
		summand /= k;
		sum += summand;
	}
	
	return sum;
}

double logarithm(double x)
{
	if (x <= 0) {
		std::cerr << "Error: Bad input for ln: " << x << std::endl;
		exit(1);
	}
	double summand = (x-1)/(x+1);	// only the first half of the summand
	double fraction_factor = summand*summand;
	double sum = summand;
	for (int k=1;
	     summand > __DBL_EPSILON__ or summand < -__DBL_EPSILON__; ++k) {
		summand *= fraction_factor;
		sum += summand/(2*k+1);
	}
	
	return 2*sum;
}

double power(double x, double y)
{
	if (x == 0) {
		return 0;
	} else if (x < 0) {
		std::cerr << "Error: Base must be positive. " << x
		<< " isn't positive." << std::endl;
		exit(1);
	} else {
		return expo(y * logarithm(x));
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		std::cerr << "Error: Not enough input." << std::endl;
		return 1;
	}
	
	double x = atof(argv[1]);
	double y = atof(argv[2]);
	
	std::cout << std::setprecision(15)
	<< x << "^" << y << " = " << power(x, y) << std::endl;
	
	return 0;
}
