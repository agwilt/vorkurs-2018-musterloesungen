#include <iostream>
#include <iomanip>
#include <cmath>

double my_sqrt(double n)
{
	double w = n/2;
	while (fabs(w*w - n) > __DBL_EPSILON__) {
		w = (w + n/w)/2;
	}

	return w;
}

int main(int argc, char *argv[])
{
	double n;
	std::cout << "Zahl eingeben: ";
	std::cin >> n;
	std::cout << std::setprecision(16) << "Die Wurzel von " << n << " ist " << my_sqrt(n) << "." << std::endl;
	return 0;
}
