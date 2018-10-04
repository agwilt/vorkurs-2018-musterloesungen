#include "Punkt.hpp"

int main()
{
	size_t dim;
	std::cout << "Dim = ";
	std::cin >> dim;
	
	double *values = new double[dim];
	for (size_t i=0; i<dim; ++i) {
		std::cout << i << ". value: ";
		std::cin >> values[i];
	}
	
	Punkt<double> p(dim, values);
	p.print();
	
	std::cout << "Norm is " << p.norm() << std::endl;
	
	delete[] values;
}
