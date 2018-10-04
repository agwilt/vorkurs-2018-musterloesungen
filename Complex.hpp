#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>

struct Punkt2 {
	Punkt2() {}
	Punkt2(double x_coor, double y_coor) : x {x_coor}, y {y_coor} {}
	double x;
	double y;
};

struct Polar {
	Polar(double radius, double angle) : r {radius}, phi {angle} {}
	double r;
	double phi;
};

struct Complex {
	Complex(double x) : re {x}, im {0} {}
	Complex(Punkt2 p) : re {p.x}, im {p.y} {}
	Complex(Polar p);
	
	Punkt2 cart_coords() const { return Punkt2 {re, im}; }
	Polar polar_coords() const { return Polar {r(), phi()}; }
	Complex mult_inverse() const { return Complex{Polar{1/r(), -phi()}}; }
	
	double r() const { return sqrt(re*re + im*im); }
	double phi() const;
	
	Complex operator+(Complex const& rhs) const;
	Complex operator-() const { return *this * (-1); }
	Complex operator*(Complex const& rhs) const;
	Complex operator*(double x) const;
	Complex operator/(Complex const& rhs) const;
	
	Complex &operator+=(Complex const& rhs) { re+=rhs.re; im+=rhs.im; return *this; }
	Complex &operator*=(double x) { re*=x; im*=x; return *this; }
	
	double re;
	double im;
};

#endif // COMPLEX_H
