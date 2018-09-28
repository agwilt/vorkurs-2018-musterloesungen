#include <iostream>
#include <iomanip>
#include <cmath>

double lazy_ans()
{
	return M_PI*M_PI/6;
}

double no_so_lazy_ans()
{
	double sum = 0;
	for (unsigned long k=1; 1.0/(k*k)>__DBL_EPSILON__; ++k) {
		sum += 1.0/(k*k);
	}

	return sum;
}

int main()
{
	std::cout << std::setprecision(16) << "Lazy version:        " << lazy_ans() << std::endl;
	std::cout << std::setprecision(16) << "Not so lazy version: " << no_so_lazy_ans() << std::endl;
}
