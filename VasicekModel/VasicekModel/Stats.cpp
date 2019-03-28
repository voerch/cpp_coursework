#include "Stats.h"
#include <cmath>
void Stats::add(double x)
{
	Sum += x;
	SumSquared += x*x;
	Count++;
}

double Stats::mean()
{
	return Sum / Count;
}

double Stats::stDev()
{
	double me = mean();
	return sqrt(SumSquared / Count - me * me);
}