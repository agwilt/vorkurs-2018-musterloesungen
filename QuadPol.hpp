#ifndef QUAD_POL_H
#define QUAD_POL_H

#include <vector>

class QuadPol {
public:
	// makes parabola ax^2 + bx + c
	QuadPol(double a, double b, double c) { _coeff[0] = c; _coeff[1] = b; _coeff[2] = a; }
	// makes constant polynomial c
	QuadPol(double c) { _coeff[2] = _coeff[1] = 0; _coeff[0] = c; }
	// makes parabola from vector of coefficients
	QuadPol(std::vector<double> v);

	QuadPol add(QuadPol const& q) const;
	QuadPol &stretch(double a);
	QuadPol shifted(double x, double y) const;

	bool goes_to_infty() const;
	double at(unsigned i) const;
	void print() const;
private:
	double _coeff[3];
};

#endif // QUAD_POL_H
