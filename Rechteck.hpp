#ifndef RECHTECK_H
#define RECHTECK_H

enum Dimension {
	x_dim = 0,
	y_dim = 1
};


class Rechteck {
public:
	Rechteck(
		double x_min,
		double x_max,
		double y_min,
		double y_max);
	
	Rechteck(Rechteck const& other);

	void print() const;
	
	double get_min(Dimension dim) const { return _min[dim]; }
	double get_max(Dimension dim) const { return _max[dim]; }
	void set_min(double new_min, Dimension dim);
	void set_max(double new_max, Dimension dim);
	
	double compute_flaecheninhalt();
	void test_validity();

private:
	double _min[2];
	double _max[2];
	double _flaecheninhalt;
};

#endif // RECHTECK_H
