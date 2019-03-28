#include "stats.h"
#include <cmath>
void Stats::add(double x)
{
	Sum += x;
	SumSquared += x * x;
	Count++;
	return;
}

double Stats::count()
{
	return Count;
}

double Stats::mean()
{
	return Sum / count();
}

double Stats::stdev()
{
	double m = mean();
	return sqrt(SumSquared / count() - m * m);
}