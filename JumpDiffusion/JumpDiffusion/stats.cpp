#include "stats.h"
#include <cmath>
void Stats::add(double x)
{
	Sum += x;
	SumSquared += x * x;
	Count++;
	return;
}

double Stats::mean()
{
	return Sum / double(Count);
}

double Stats::stdev()
{
	double m = mean();
	return sqrt(Sum / Count - m * m);
}