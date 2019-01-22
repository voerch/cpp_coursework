#include "stats.h"
#include <cmath>
#include <iostream>
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
	MinusMean += pow((x - mean()), 2);
}

double Stats1::mean()
{
	return Sum / NumberOfElements;
}

double Stats1::stdev()
{
	return sqrt(MinusMean / NumberOfElements);
}

Stats2::Stats2()
{
	Sum = 0;
	NumberOfElements = 0;
}

void Stats2::add(double a, double b)
{
	x.add(a);
	y.add(b);
	NumberOfElements += 1;
	Sum += (a * b);
}

double Stats2::cov()
{
	return (Sum / NumberOfElements) - (x.mean() * y.mean());
}

double Stats2::corr()
{
	covariance = cov();
	return covariance / (x.stdev() * y.stdev());
}

void Stats2::parameters()
{
	covariance = cov();
	m = covariance / pow(x.stdev(),2);
	c = y.mean() - (m * x.mean());

	std::cout << "Equation: y = "  << m << " * " << "x + " << c << std::endl;
}