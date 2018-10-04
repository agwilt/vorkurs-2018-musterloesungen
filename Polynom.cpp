#include "Polynom.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <boost/math/special_functions/binomial.hpp>

template <typename T>
T power(T x, unsigned n)
{
	T ans = 1;
	for (; n > 0; x*=x, n/=2) {
		if (n%2) {
			ans *= x;
		}
	}
	return ans;
}

// makes (t-x)^n
template <typename T>
Polynom<T>::Polynom(T x, unsigned n) : _coefficients{}
{
	for (unsigned k=0; k<=n; ++k) {
		// build a_k
		_coefficients.push_back(static_cast<T>(static_cast<long long>(boost::math::binomial_coefficient<long double>(n, k))) * power(-x, n-k));
	}
}

template <typename T>
Polynom<T> Polynom<T>::operator+(Polynom<T> const& q) const
{
	std::vector<T> v;

	if (size() >= q.size()) {
		v = _coefficients;
		for (size_t i=0; i<q.size(); ++i)
			v[i] += q[i];
	} else {
		v = q._coefficients;
		for (size_t i=0; i<size(); ++i)
			v[i] += _coefficients[i];
	}

	return Polynom{v};
}

template <typename T>
Polynom<T> Polynom<T>::operator-() const
{
	return *this * static_cast<T>(-1);
}

template <typename T>
Polynom<T> &Polynom<T>::operator+=(Polynom<T> const& q)
{
	for (size_t i=0; (i<size()) and (i<q.size()); ++i) {
		_coefficients[i] += q[i];
	}
	for (size_t i=size()-1; i<q.size(); ++i) {
		_coefficients.push_back(q[i]);
	}

	return *this;
}

template <typename T>
Polynom<T> &Polynom<T>::operator*=(T const a)
{
	for (unsigned i=0; i<size(); ++i) {
		_coefficients[i] *= a;
	}
	return *this;
}

template <typename T>
Polynom<T> Polynom<T>::operator*(T const a) const
{
	std::vector<T> v {_coefficients};
	for (auto &x : v)
		x *= a;
	return Polynom<T> {v};
}

template <typename T>
Polynom<T> &Polynom<T>::operator*=(Polynom<T> const& q)
{
	return (*this = *this * q);
}

template <typename T>
Polynom<T> Polynom<T>::operator*(Polynom<T> const& q) const
{
	size_t d = q.deg() + deg();

	std::vector<T> v(d+1, 0);

	for (size_t i=0; i<size(); ++i) {
		for (size_t j=0; j<q.size(); ++j) {
			v[i+j] += _coefficients[i] * q[j];
		}
	}

	return Polynom<T>{v};
}

template <typename T>
T Polynom<T>::operator()(T x) const
{
	T ans {0};
	for (size_t i=0; i<size(); ++i) {
		ans += _coefficients[i] * power(x, i);
	}
	return ans;
}

template <typename T>
void Polynom<T>::debug_print() const
{
	std::cout << "Size: " << size() << std::endl;
	std::cout << "Degree: " << deg() << std::endl;
	std::cout << "First coefficient: " << _coefficients[0] << std::endl;
	std::cout << *this;
}

template <typename T>
void Polynom<T>::tidy_up()
{
	while ((_coefficients.size() > 1) and (_coefficients.back() == 0)) {
		_coefficients.pop_back();
	}
}

template <typename T>
Polynom<T> Polynom<T>::shifted(T x, T y) const
{
	Polynom<T> p{_coefficients[0] + y};	// y-shifting
	for (unsigned i=1; i<size(); ++i) {
		// Add a_i * (t-x)^i
		p += Polynom<T>(x, i) * _coefficients[i];
	}
	return p;
}

template <typename T>
std::ostream &Polynom<T>::write(std::ostream &os) const
{
	os << "(";
	for (int d=deg(); d>=0; --d) {
		os << _coefficients[d];
		if (d > 0)
			os << "x^" << d << " + ";
	}
	os << ")";
	return os;
}

template class Polynom<double>;
template class Polynom<long double>;
template class Polynom<int>;
template class Polynom<long>;
template class Polynom<long long>;

template class Polynom<Polynom<double>>;
template class Polynom<Polynom<long double>>;
