#include "bruch.hpp"

#include <iostream>

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	while (b != 0) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

Bruch::Bruch(int zaehler, int nenner) : _zaehler(zaehler), _nenner(nenner)
{
	_kuerze();
}

void Bruch::set_zaehler(int zaehler)
{
	_zaehler = zaehler;
	_kuerze();
}

void Bruch::set_nenner(int nenner)
{
	_nenner = nenner;
	_kuerze();
}

void Bruch::print() const
{
	std::cout << _zaehler << " / " << _nenner << std::endl;
}

Bruch Bruch::multiplizieren(Bruch const& bruch) const
{
	return Bruch(_zaehler * bruch.get_zaehler(), _nenner * bruch.get_nenner());
}

Bruch Bruch::addieren(Bruch const& bruch) const
{
	return Bruch(_nenner * bruch.get_zaehler() + _zaehler * bruch.get_nenner(),
		     _nenner * bruch.get_nenner());
}

void Bruch::_kuerze()
{
	int g = gcd(_zaehler, _nenner);
	_zaehler /= g;
	_nenner /= g;
}
