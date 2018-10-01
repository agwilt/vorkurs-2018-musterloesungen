#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

void print_sorted(std::vector<unsigned> const& zahlen)
{
	unsigned const n = zahlen.size();
	std::vector<bool> forbidden(n, false);

	for (unsigned i=0; i<n; ++i) {
		int min_pos = -1;
		unsigned min = UINT_MAX;
		for (unsigned j=0; j<n; ++j) {
			if (zahlen[j] <= min and not forbidden[j]) {
				min = zahlen[j];
				min_pos = j;
			}
		}
		std::cout << min << std::endl;
		forbidden[min_pos] = true;
	}
}

int main(int argc, char *argv[])
{
	std::vector<unsigned> zahlen;
	for (int i=1; i<argc; ++i) {
		zahlen.push_back(strtoul(argv[i], nullptr, 10));
	}
	print_sorted(zahlen);

	return 0;
}
