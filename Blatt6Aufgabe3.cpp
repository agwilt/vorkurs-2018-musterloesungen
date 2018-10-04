struct normal_form {
	normal_form(sp_form f) {
		a = f.a;
		b = -2*f.d*f.a;
		c = f.e + f.a*f.d*f.d;
	}
	normal_form(fakt_form f) {
		a = f.a;
		b = -f.a * (f.x_1 + f.x_2);
		c = f.a * f.x_1 * f.x_2;
	}
	double a;
	double b;
	double c;
};

struct sp_form {
	double a;
	double d;
	double e;
};

struct fakt_form {
	double a;
	double x_1;
	double x_2;
};

class QuadPol {
public:
	QuadPol(double a, double b, double c) : _data{a, b, c} {}
	QuadPol(normal_form f) : _data(f) {}

	QuadPol(sp_form f) : _data(f) {}

	QuadPol(fakt_form f) : _data(f) {}

	QuadPol addieren(QuadPol const& q) const
	{
		normal_form f = q.get_normal_form();
		return QuadPol(_data.a + f.a, _data.b + f.b, _data.c + f.c);
	}

	bool goes_to_infinity() const
	{
		return (_data.a > 0) or ((_data.a == 0) and _data.b > 0);
	}

	void shift(double x, double y)
	{
		sp_form f = get_sp_form();
		f.d -= x;
		f.e += y;
		_data = normal_form(f);
	}

	normal_form get_normal_form() const { return _data };
	sp_form get_sp_form() const { return sp_form(_data) };
	fakt_form get_fakt_form() const { return fakt_form(_data) };

private:
	normal_form _data;
};
