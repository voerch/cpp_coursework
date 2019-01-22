#include "stats.h"
#include <cmath>
#include <iostream>

Stats1::Stats1()
{
	Sum = 0;
	NumberOfElements = 0;	
	x_Squared = 0;
}

void Stats1::add(double x)
{
	Sum += x;
	NumberOfElements += 1;
	x_Squared += pow(x, 2);
}

double Stats1::mean()
{
	return Sum / NumberOfElements;
}

double Stats1::stdev()
{
	double mean2 = mean();
	double stdeviation = sqrt(abs((x_Squared + (NumberOfElements * pow(mean2, 2)) - (2 * mean2 * Sum)) / NumberOfElements));
	return stdeviation;
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
	return cov() / (x.stdev() * y.stdev());
}

void Stats2::parameters()
{
	//Calculates the best fitting straight line for the given data points.
	double m = cov() / pow(x.stdev(),2);
	double c = y.mean() - (m * x.mean());

	std::cout << "Equation: y = "  << m << " * " << "x + " << c << std::endl;
}