#ifndef RECHTECK_H
#define RECHTECK_H

#include <string>
#include <vector>

enum Dimension {
	x_dim = 0,
	y_dim = 1
};

template <typename T>
class Rechteck {
public:
	Rechteck() : _min {0,0}, _max {0,0} {}
	Rechteck(
		T x_min,
		T x_max,
		T y_min,
		T y_max);

	void print() const;
	
	T get_min(Dimension dim) const { return _min[dim]; }
	T get_max(Dimension dim) const { return _max[dim]; }
	void set_min(T new_min, Dimension dim);
	void set_max(T new_max, Dimension dim);
	
	bool touches(Rechteck const& rhs) const;
	T compute_flaecheninhalt();
	void test_validity();

private:
	T _min[2];
	T _max[2];
	T _flaecheninhalt;
};

template <typename T>
class RechteckSet {
public:
	RechteckSet(std::string filename);
	RechteckSet(std::vector<Rechteck<T>> rechtecke) : _rechtecke{rechtecke} {}
	bool are_overlaps() const;

	Rechteck<T> const& operator[](size_t i) const { return _rechtecke[i]; }
private:

	std::vector<Rechteck<T>> _rechtecke;
};

#endif // RECHTECK_H
