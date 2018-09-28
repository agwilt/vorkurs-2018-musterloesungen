#include <iostream>

long folge_recursive(unsigned n)
{
	if (n <= 2)
		return 1;
	else
		return 2*folge_recursive(n-2) + folge_recursive(n-1) + 2*folge_recursive(n-3);
}

long folge_iterative(unsigned n)
{
	if (n <= 2)
		return 1;
	
	long *a = new long[n+1];	// Fuer {a_0, ... ,a_n}
	a[0] = a[1] = a[2] = 1;
	for (unsigned i = 3; i <= n; ++i) {
		a[i] = 2*a[i-2] + a[i-1] + 2*a[i-3];
	}
	
	long a_n = a[n];
	delete[] a;
	return a_n;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: No argument supplied.\n";
		return 1;
	}
	
	int n = atoi(argv[1]);
	std::cout << "Rekursiv: " << folge_recursive(n) << std::endl;
	std::cout << "Iterativ: " << folge_iterative(n) << std::endl;
}
