#include "Polynom.hpp"
#include <iostream>
#include <vector>

int main()
{
	double a,b,c;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	std::cout << "Enter c: ";
	std::cin >> c;
	Polynom<double> p(std::vector<double> {c,b,a});
	std::cout << "p(x) = " << p << std::endl;
	p *= 2;
	std::cout << "p(x) = " << p << std::endl;
	
	Polynom<Polynom<double>> q {std::vector<Polynom<double>> {p, Polynom<double>(4)}};
	std::cout << "q(x) = 4x + p = " << q << std::endl;
	
	return 0;
}
