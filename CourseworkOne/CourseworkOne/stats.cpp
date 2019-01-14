#include "stats.h"
#include <cmath>


Stats1::Stats1()
{
	Sum = 0;
	NumberOfElements = 0;
	MinusMean = 0;
}

void Stats1::add(double x) 
{
	Sum += x;
	NumberOfElements += 1;
	MinusMean += pow(x - (Sum / NumberOfElements), 2);
}

double Stats1::mean()
{
	return Sum / NumberOfElements;;
}

double Stats1::StDev()
{
	return sqrt(MinusMean / NumberOfElements);
}


void Stats2::add(double x, double y)
{
	SumXY += x*y;
	SumX += x;
	SumY += y;
	MinusMeanX += pow(x - (SumX / NumberOfElements), 2);
	MinusMeanY += pow(y - (SumY / NumberOfElements), 2);
	NumberOfElements += 1;
}

double Stats2::Covariance()
{
	Cov = (SumXY / NumberOfElements) - (SumX * SumY / pow(NumberOfElements,2);
	return Cov;
}

double Stats2::Correlation()
{
	double VarX = MinusMeanX / NumberOfElements;
	double VarY = MinusMeanY / NumberOfElements;

	return Cov / sqrt(VarX * VarY);
}