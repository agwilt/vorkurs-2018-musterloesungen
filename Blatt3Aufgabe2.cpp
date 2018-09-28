#include <iostream>
#include <cmath>
#include <iomanip>

double cos_reihe(double x)
{
	double sum = 0;
	double summand = 1;
	for (int k=0; summand > __DBL_EPSILON__ or summand < -__DBL_EPSILON__;) {
		sum += summand;
		k += 2;
		summand *= -1;
		summand *= x*x;
		summand /= k*(k-1);
	}

	return sum;
}

// long long, damit der overflow moeglichst spaet passiert
long long fakultaet(int k)
{
	long long ans = 1;
	for (; k>0; k--) {
		ans *= k;
	}
	return ans;
}

double naive_cos_reihe(double x)
{
	// because 0^0 is undefined:
	if (x == 0) return 1;
	
	double sum = 0;
	for (int k=0; k < 10; ++k) {
		double summand = pow(x, 2*k) / fakultaet(2*k);
		if (k%2 == 0) {
			sum += summand;
		} else {
			sum -= summand;
		}
	}
	return sum;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: No argument x." << std::endl;
		return 1;
	}

	double x = atof(argv[1]);
	std::cout << std::setprecision(16) << cos_reihe(x) << std::endl;
	std::cout << std::setprecision(16) << naive_cos_reihe(x) << std::endl;

	return 0;
}
