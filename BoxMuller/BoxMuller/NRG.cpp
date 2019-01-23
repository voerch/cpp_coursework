#include "NRG.h"
#include <cstdlib>

const double TwoPi = 2 * 3.14159265358979323846;

double NRG::generate()
{
	double z1, z2, u1, u2;
	u1 = rand() * (1.0 / RAND_MAX);
	u2 = rand() * (1.0 / RAND_MAX);

	if (u1 > 0 && u2 > 0) {
		z1 = sqrt(-2.0 * log(u1)) * cos(u2 * TwoPi);
		z2 = sqrt(-2.0 * log(u1)) * sin(u2 * TwoPi);
	}
	else
		z2 = 0;

	return z2;
}