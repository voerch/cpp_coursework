#include "EurOption.h"
#include <cmath>
#include<iostream>
#include "stats.h"

double N(double x)
{
	return 0.5 * erfc(-x * sqrt(0.5));
}

double Factorial(double Number) 
{
	return (Number > 1) ? Number * Factorial(Number - 1) : (1);
}

double EurOption::d_plus(double S0, double sigma, double r)
{
	return (log(S0 / K) + (r + 0.5*pow(sigma, 2.0))*T) / (sigma*sqrt(T));
}

double EurOption::d_minus(double S0, double sigma, double r)
{
	return d_plus(S0, sigma, r) - sigma*sqrt(T);
}

double EurCall::PriceByBSFormula(double S0, double sigma, double r)
{
	return S0*N(d_plus(S0, sigma, r)) - K*exp(-r*T)*N(d_minus(S0, sigma, r));
}

double EurCall::PriceByJDFormula(double S0,	double sigma, double r, double s, double m, double lambda, int Counter)
{
	double sigmaN, BS, rN, Sum=0;
	double k = exp(m + (pow(s, 2) / 2)) - 1;
	double lambdaN = lambda * (1 + k);

	for (int n = 0; n < Counter; n++) {
		sigmaN = sqrt(pow(sigma, 2) + (n * pow(s, 2) / T));
		rN = r - (lambda * k) + ((n * log(1 + k)) / T);
		BS = PriceByBSFormula(S0, sigmaN, rN);
		Sum += (exp(-lambdaN * T) * pow(lambdaN*T, n) * BS) / Factorial(n);
	}
	
	return Sum;
}

double EurCall::Payoff(double S)
{
	return (S > K) ? S - K : 0;
}

double EurOption::PriceByJDMC(JDModel Model, int samplingDates, int nPaths)
{
	SamplePaths SP;
	Model.GenerateSamplePaths(SP, T, samplingDates, nPaths);
	Stats Payoffs;
	for (SamplePaths::iterator it = SP.begin(); it != SP.end();++it)
	{
		Payoffs.add(Payoff(*it));
	}

	double Price = Payoffs.mean() * exp(-Model.r * T);
	double PricingError = Payoffs.stdev() * exp(-Model.r * T) / sqrt(double(nPaths));
	cout << "Monte Carlo Price: " << Price << " +/- " << PricingError;
	return Price;
}