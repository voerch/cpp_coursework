#include "VasicekModel.h"
#include <cmath>

const double PI = 4 * atan(1.0);

double Gauss()
{
	double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
	double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

	return sqrt(-2 * log(U1)) * cos(2 * PI * U2);
}

void VasicekModel::GenerateSamplePath(SamplePath& S, double T, int timeSplit)
{
	double TimeStep = T / timeSplit;
	double delta_r;
	double r0 = r;
	
	S.reserve(timeSplit);

	for (int i = 0; i < timeSplit; i++)
	{
		S.push_back(r0);
		delta_r = (a*(b - r0)*TimeStep) + (sigma * sqrt(TimeStep) * Gauss());
		r0 = delta_r + r0;
		
	}

}