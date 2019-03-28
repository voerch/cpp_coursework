#include "EurOption.h"
#include <cmath>
#include <iostream>

double PI = 4 * atan(1.0);

double CDF(double x)
{
	return 0.5 * erfc(-x * sqrt(0.5));
}

double PDF(double x)
{
	return sqrt(0.5 * (1/PI)) * exp(-0.5 * pow(x,2));
}

double EurOption::dPlus(double S0, double sigma, double r)
{
	return (log(S0 / Strike) + (r + 0.5*pow(sigma, 2.0))*TimeToExpiry) / (sigma*sqrt(TimeToExpiry));
}

double EurOption::dMinus(double S0, double sigma, double r)
{
	return dPlus(S0, sigma, r) - sigma * sqrt(TimeToExpiry);
}

double Call::PriceByBS(double S0, double r, double sigma)
{
	return S0 * CDF(dPlus(S0, sigma, r)) - Strike * exp(-r * TimeToExpiry)*CDF(dMinus(S0, sigma, r));
}

double Call::PriceDelta(double S0, double r, double sigma)
{
	return CDF(dPlus(S0, sigma, r));
}

double Call::PriceGamma(double S0, double r, double sigma)
{
	return PDF(dPlus(S0, sigma, r)) / (S0 * sigma * sqrt(TimeToExpiry));
}

double Call::PriceTheta(double S0, double r, double sigma)
{
	return (-(S0 * PDF(dPlus(S0, sigma, r)) * sigma) / (2*sqrt(TimeToExpiry))) - (r * Strike * exp(-r * TimeToExpiry) * CDF(dMinus(S0, sigma, r)));
}