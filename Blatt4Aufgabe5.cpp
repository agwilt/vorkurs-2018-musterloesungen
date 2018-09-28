#include <iostream>
#include <vector>

std::vector<int> divisors(int n)
{
	std::vector<int> ans;
	
	for (int k=1; k <= n; ++k) {
		if (n%k == 0) {
			ans.push_back(k);
		}
	}
	
	return ans;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: Gimme number!\n";
		return 1;
	}
	
	int n = atoi(argv[1]);
	for (auto k : divisors(n)) {
		std::cout << k << std::endl;
	}
	
	return 0;
}
