#ifndef POLYNOM_H
#define POLYNOM_H

#include <vector>
#include <ostream>

// TODO: Take out all the bugs

template <typename T>
class Polynom {
public:
	Polynom(T x) : _coefficients {x} {}
	Polynom(std::vector<T> const& v) : _coefficients(v) { tidy_up(); }
	explicit Polynom(T x, unsigned n);	// makes (t-x)^n

	Polynom operator-() const;
	Polynom operator+(Polynom const& q) const;
	Polynom &operator+=(Polynom const& q);
	Polynom operator*(Polynom const& q) const;
	Polynom &operator*=(Polynom const& q);
	Polynom operator*(T const a) const;
	Polynom &operator*=(T const a);
	T operator[](size_t i) const { return _coefficients[i]; }
	T operator()(T x) const;

	bool operator==(Polynom const& q) const { return q._coefficients == _coefficients; }
	Polynom shifted(T x, T y) const;

	void debug_print() const;
	size_t deg() const { return _coefficients.size() - 1; }
	size_t size() const { return _coefficients.size(); }
	
	std::ostream &write(std::ostream &os) const;
private:
	void tidy_up();
	std::vector<T> _coefficients;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Polynom<T> const &p) { return p.write(os); }

#endif // POLYNOM_H
