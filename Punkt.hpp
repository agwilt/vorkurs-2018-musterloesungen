#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

template <typename T>
class Punkt {
public:
	Punkt(size_t dim, std::vector<T> coords) : _coords {coords}
	{
		if (coords.size() != dim)
			throw std::runtime_error("Bad dimension.");
		update_norm();
	}

	Punkt(size_t dim, T *coords) : _coords {}
	{
		_coords.reserve(dim);
		for (size_t i=0; i<dim; ++i) {
			_coords.push_back(coords[i]);
		}
		update_norm();
	}
	
	T const& operator[](size_t i)
	{
		return _coords[i];
	}
	
	T norm() const { return _norm; }
	
	void print() const
	{
		for (auto const& x : _coords)
			std::cout << x << std::endl;
	}
	
private:
	void update_norm()
	{
		_norm = 0;
		for (size_t i=0; i<_coords.size(); ++i)
			_norm += std::abs(_coords[i]);
	}
	
	T _norm;
	std::vector<T> _coords;
};

#endif // PUNKT_H
