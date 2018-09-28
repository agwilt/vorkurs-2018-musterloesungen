#include "Blatt3Aufgabe3.h"

double betrag(double const x)
{
	return (x>0)?x:-x;
}

double cos(double x)
{
	double sum = 0;
	double summand = 1;
	for (int k=0; betrag(summand) > __DBL_EPSILON__;) {
		sum += summand;
		k += 2;
		summand *= -1;
		summand *= x*x;
		summand /= k*(k-1);
	}

	return sum;
}

double wurzel(double const x)
{
	double w = x/2;
	while (betrag(w*w - x) > __DBL_EPSILON__) {
		w = (w + x/w)/2;
	}

	return w;
}
