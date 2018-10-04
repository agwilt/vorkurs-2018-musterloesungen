#include "QuadPol.hpp"

#include <stdexcept>
#include <iostream>

QuadPol::QuadPol(std::vector<double> v)
{
	if (v.size() > 3) {
		throw std::runtime_error("Error: Bad input in constructor.");
	}

	for (unsigned i=0; i<v.size(); ++i) {
		_coeff[i] = v[i];
	}
}

QuadPol QuadPol::add(QuadPol const& q) const
{
	return QuadPol(_coeff[2] + q.at(2), _coeff[1] + q.at(1), _coeff[0] + q.at(0));
}

QuadPol &QuadPol::stretch(double a)
{
	for (unsigned i=0; i<3; ++i)
		_coeff[i] *= a;
	return *this;
}

QuadPol QuadPol::shifted(double x, double y) const
{
	// a(t-x)^2 + b(t-x) + c + y
	// = at^2 + (b-2ax)t + (ax^2 - bx + c + y)
	return QuadPol(_coeff[2],
	               _coeff[1] - 2*_coeff[2]*x,
	               _coeff[2]*x*x - _coeff[1]*x + _coeff[0] + y);
}

bool QuadPol::goes_to_infty() const
{
	if (_coeff[2] > 0) {
		return true;
	} else if ((_coeff[2] == 0) and (_coeff[1] > 0)) {
		return true;
	} else {
		return false;
	}
}

double QuadPol::at(unsigned i) const
{
	if (i >= 3) {
		throw std::runtime_error("Error: Bad index.");
	}

	return _coeff[i];
}

void QuadPol::print() const
{
	std::cout << _coeff[2] << "x^2 + " << _coeff[1] << "x + " << _coeff[0] << std::endl;
}
