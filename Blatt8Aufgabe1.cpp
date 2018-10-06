#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

int main(int argc, char *argv[])
{
	// open file
	std::vector<unsigned> zahlen{};
	if (argc < 2) {
		std::cerr << "Error: No filename.\n";
		return 1;
	}
	std::ifstream file(argv[1]);
	if (not file) {
		std::cerr << "Couldn't open file: " << argv[1] << std::endl;
		return 1;
	}
	
	// read numbers
	for (unsigned k; file >> k; zahlen.push_back(k));
	
	if (zahlen.empty()) {
		std::cerr << "Error: No numbers supplied.\n";
		return 2;
	}
	
	// calculate kgV
	unsigned kgv = zahlen[0];
	for (auto k : zahlen) {
		unsigned ggt = std::gcd(kgv, k);
		kgv = (kgv * k) / ggt;
	}
	
	std::cout << kgv << std::endl;
	
	return 0;
}
