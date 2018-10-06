#include "Rechteck.hpp"

#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Please supply file name.\n";
		return 1;
	}
	
	std::string filename{argv[1]};
	RechteckSet<long long> rechtecke{filename};
	
	if (rechtecke.are_overlaps()) {
		std::cout << "Overlap!\n";
	} else {
		std::cout << "No overlap.\n";
	}
	
	return 0;
}
