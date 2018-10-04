#include "QuadPol.hpp"

int main()
{
	QuadPol p(0.5, 2, 2);
	QuadPol q(0.5, -2, -3);
	QuadPol r = p.add(q);
	r.print();

	QuadPol s = r.shifted(1, 0);
	s.print();

	return 0;
}
