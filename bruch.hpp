#ifndef BRUCH_H
#define BRUCH_H

class Bruch {
public:
	Bruch(int zahler, int nenner);

	void print() const;
	Bruch multiplizieren(Bruch const& bruch) const;
	Bruch addieren(Bruch const& bruch) const;

	int get_zaehler() const { return _zaehler; }
	int get_nenner() const { return _nenner; }
	void set_zaehler(int zaehler);
	void set_nenner(int nenner);
private:
	void _kuerze();

	int _zaehler;
	int _nenner;
};

#endif // BRUCH_H
