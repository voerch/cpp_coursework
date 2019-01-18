#include "NRG.h"
#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;

double NRG::generate() {
	double z;
	double u1 = rand() / (double)RAND_MAX;
	double u2 = rand() / (double)RAND_MAX;
	if (u1 > 0 && u2 > 0) {
		z = sqrt(-2 * log(u1)) * cos(2 * u2 * pi);
	}
	else
		z = 0;
	return z;

}