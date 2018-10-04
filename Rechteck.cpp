#include "Rechteck.hpp"

#include <iostream>

Rechteck::Rechteck(
		double x_min,
		double x_max,
		double y_min,
		double y_max)
{
	_min[Dimension::x_dim] = x_min;
	_max[Dimension::x_dim] = x_max;
	_min[Dimension::y_dim] = y_min;
	_max[Dimension::y_dim] = y_max;
	test_validity();
}

Rechteck::Rechteck(Rechteck const& other)
{
	_min[Dimension::x_dim] = other.get_min(Dimension::x_dim);
	_min[Dimension::y_dim] = other.get_min(Dimension::y_dim);
	_max[Dimension::x_dim] = other.get_max(Dimension::x_dim);
	_max[Dimension::y_dim] = other.get_max(Dimension::y_dim);
	test_validity();
}

void Rechteck::print() const
{
	std::cout << "[" << _min[Dimension::x_dim] << ", " << _max[Dimension::x_dim] << "] x ["
		<< _min[Dimension::y_dim] << ", " << _max[Dimension::y_dim] << "]" << std::endl;
}

double Rechteck::compute_flaecheninhalt()
{
	double d_x = _max[Dimension::x_dim] - _min[Dimension::x_dim];
	double d_y = _max[Dimension::y_dim] - _min[Dimension::y_dim];
	return (_flaecheninhalt = d_x*d_y);
}

void Rechteck::set_min(double new_min, Dimension dim)
{
	_min[dim] = new_min;
	test_validity();
}

void Rechteck::set_max(double new_max, Dimension dim)
{
	_max[dim] = new_max;
	test_validity();
}

void Rechteck::test_validity()
{
	if ((_min[0] > _max[0]) or (_min[1] > _max[1]))
		throw std::runtime_error("Error: Bad rectangle. Get correct rect.");
}
