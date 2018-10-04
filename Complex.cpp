#include "Complex.hpp"

Complex::Complex(Polar p)
{
	re = p.r * cos(p.phi);
	im = p.r * sin(p.phi);
}

double Complex::phi() const
{
	if (re == 0) {
		return M_PI / 2.0;
	} else {
		return atan(im / re);
	}
}

Complex Complex::operator+(Complex const& rhs) const
{
	Punkt2 p {re+rhs.re, im+rhs.im};
	return Complex {p};
}

Complex Complex::operator*(Complex const& rhs) const
{
	Punkt2 p;
	p.x = re*rhs.re - im*rhs.im;
	p.y = re*rhs.im + im*rhs.re;
	return Complex {p};
}

Complex Complex::operator*(double x) const
{
	Punkt2 p {re*x, im*x};
	return Complex {p};
}

Complex Complex::operator/(Complex const& rhs) const
{
	return *this * rhs.mult_inverse();
}
