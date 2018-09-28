#include <iostream>

long long fakultaet(long long n)		// mistake
{
	long long ergebnis = 1;	// mistake

	while (n > 0) {		// mistake
		ergebnis *= n;
		--n;
	}

	return ergebnis;
}

int main()
{
	long long add2fak;
	const int a = 5;
	const int b = 16;

	add2fak = fakultaet(a) + fakultaet(b);	//mistake
	std::cout << "short " << sizeof(short) << std::endl;
	std::cout << "int " << sizeof(int) << std::endl;
	std::cout << "long " << sizeof(long) << std::endl;
	std::cout << "long long " << sizeof(long long) << std::endl;
	std::cout << a << "! + " << b << "! = " << add2fak << std::endl;	// mistake

	return 0;		// mistake
}
