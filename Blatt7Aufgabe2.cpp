#include "Rechteck.hpp"

#include <iostream>

int main()
{
	double x_min, x_max, y_min, y_max;
	std::cout << "x_min = ";
	std::cin >> x_min;
	std::cout << "x_max = ";
	std::cin >> x_max;
	std::cout << "y_min = ";
	std::cin >> y_min;
	std::cout << "y_max = ";
	std::cin >> y_max;

	try {
		Rechteck r(x_min, x_max, y_min, y_max);
		
		r.print();
		std::cout << r.compute_flaecheninhalt() << std::endl;
		
	} catch  (std::runtime_error const& e) {
		std::cerr << "Bad Rechteck.\n";
		return 1;
	}

	return 0;
}
