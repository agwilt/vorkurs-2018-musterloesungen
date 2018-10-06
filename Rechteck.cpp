#include "Rechteck.hpp"

#include <iostream>
#include <fstream>

template <typename T>
Rechteck<T>::Rechteck(
		T x_min,
		T x_max,
		T y_min,
		T y_max)
{
	_min[Dimension::x_dim] = x_min;
	_max[Dimension::x_dim] = x_max;
	_min[Dimension::y_dim] = y_min;
	_max[Dimension::y_dim] = y_max;
	test_validity();
}

template <typename T>
void Rechteck<T>::print() const
{
	std::cout << "[" << _min[Dimension::x_dim] << ", " << _max[Dimension::x_dim] << "] x ["
		<< _min[Dimension::y_dim] << ", " << _max[Dimension::y_dim] << "]" << std::endl;
}

template <typename T>
T Rechteck<T>::compute_flaecheninhalt()
{
	T d_x = _max[Dimension::x_dim] - _min[Dimension::x_dim];
	T d_y = _max[Dimension::y_dim] - _min[Dimension::y_dim];
	return (_flaecheninhalt = d_x*d_y);
}

template <typename T>
void Rechteck<T>::set_min(T new_min, Dimension dim)
{
	_min[dim] = new_min;
	test_validity();
}

template <typename T>
void Rechteck<T>::set_max(T new_max, Dimension dim)
{
	_max[dim] = new_max;
	test_validity();
}

template <typename T>
void Rechteck<T>::test_validity()
{
	if ((_min[0] > _max[0]) or (_min[1] > _max[1])) {
		std::cerr << "WARNING: Found silly rectangle:\n";
		print();
		throw std::runtime_error("Error: Bad rectangle. Get correct rect.");
	}
}

template <typename T>
bool Rechteck<T>::touches(Rechteck const& rhs) const
{
	return ((get_min(Dimension::x_dim) <= rhs.get_max(Dimension::x_dim)) and (get_max(Dimension::x_dim) >= rhs.get_min(Dimension::x_dim))
		and (get_min(Dimension::y_dim) <= rhs.get_max(Dimension::y_dim)) and (get_max(Dimension::y_dim) >= rhs.get_min(Dimension::y_dim)));
}

// RechteckSet:

template <typename T>
bool RechteckSet<T>::are_overlaps() const
{
	for (size_t i=0; i<_rechtecke.size(); ++i) {
		for (size_t j=i+1; j < _rechtecke.size(); ++j) {
			if (_rechtecke[i].touches(_rechtecke[j])) {
				return true;
			}
		}
	}

	return false;
}

template <typename T>
RechteckSet<T>::RechteckSet(std::string filename) : _rechtecke{}
{
	std::ifstream file{filename};
	if (not file.is_open()) {
		throw std::runtime_error("Couldn't open file.");
	}
	
	T x_min, x_max, y_min, y_max;
	while (file >> x_min >> x_max >> y_min >> y_max){
		_rechtecke.push_back(Rechteck<T>{x_min, x_max, y_min, y_max});
	}

	/*
	FILE *fp = fopen(filename.c_str(), "r");
	if (not fp) {
		throw std::runtime_error("Couldn't open file.");
	}
	
	T x_min, x_max, y_min, y_max;
	while (fscanf(fp, "%ld %ld %ld %ld\n", &x_min, &x_max, &y_min, &y_max) == 4) {
		_rechtecke.push_back(Rechteck<T>{x_min, x_max, y_min, y_max});
	}
	*/
}

//template class Rechteck<float>;
//template class Rechteck<double>;
//template class Rechteck<long double>;
//template class Rechteck<short>;
//template class Rechteck<int>;
//template class Rechteck<long>;
template class Rechteck<long long>;

//template class RechteckSet<float>;
//template class RechteckSet<double>;
//template class RechteckSet<long double>;
//template class RechteckSet<short>;
//template class RechteckSet<int>;
//template class RechteckSet<long>;
template class RechteckSet<long long>;
