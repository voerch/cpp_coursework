#include "EurOption.h"
#include <cmath>
#include <iostream>
using namespace std;

double N(double x)
{
	double gamma = 0.2316419;     double a1 = 0.319381530;
	double a2 = -0.356563782;   double a3 = 1.781477937;
	double a4 = -1.821255978;   double a5 = 1.330274429;
	double pi = 4.0*atan(1.0); double k = 1.0 / (1.0 + gamma*x);
	if (x >= 0.0)
	{
		return 1.0 - ((((a5*k + a4)*k + a3)*k + a2)*k + a1)
			*k*exp(-x*x / 2.0) / sqrt(2.0*pi);
	}
	else return 1.0 - N(-x);
}

double NormalPDF(double x)
{
	return (1 / sqrt(2 * 3.14159265359)) * exp(-pow(x, 2) / 2);
}

double EurOption::d_plus(double S0, double sigma, double r)
{
	return (log(S0 / K) + (r + 0.5*pow(sigma, 2.0))*T) / (sigma*sqrt(T));
}

double EurOption::d_minus(double S0, double sigma, double r)
{
	return d_plus(S0, sigma, r) - sigma*sqrt(T);
}

double EurCall::PriceByBSFormula(double S0,	double sigma, double r)
{
	return S0*N(d_plus(S0, sigma, r)) - K*exp(-r*T)*N(d_minus(S0, sigma, r));
}

double EurPut::PriceByBSFormula(double S0, double sigma, double r)
{
	return -S0*N(-d_plus(S0, sigma, r)) + K*exp(-r*T)*N(-d_minus(S0, sigma, r));
}

//Copied to formulas from https://en.wikipedia.org/wiki/Greeks_(finance)

double EurCall::DeltaByBSFormula(double S0, double sigma, double r)
{
	return N(d_plus(S0, sigma, r));
}
double EurCall::GammaByBSFormula(double S0, double sigma, double r)
{
	return NormalPDF(d_plus(S0, sigma, r)) / (S0*sigma*sqrt(T));
}
double EurCall::ThetaByBSFormula(double S0, double sigma, double r)
{
	return (-(S0*NormalPDF(d_plus(S0, sigma, r))*sigma) / (2 * sqrt(T))) - (r*K*exp(-r*T)*N(d_minus(S0, sigma, r)));
}

double EurPut::DeltaByBSFormula(double S0, double sigma, double r)
{
	return N(-d_plus(S0, sigma, r));
}
double EurPut::GammaByBSFormula(double S0, double sigma, double r)
{
	return K*exp(-r*T)*NormalPDF(d_minus(S0, sigma, r)) / (pow(S0, 2)*sigma*sqrt(T));
}
double EurPut::ThetaByBSFormula(double S0, double sigma, double r)
{
	return (-(S0*NormalPDF(d_plus(S0, sigma, r))*sigma) / (2 * sqrt(T))) + (r*K*exp(-r*T)*N(d_minus(S0, sigma, r)));
}

//structa tanimla
//currying

ostream& operator<<(ostream& stream, EurCall &Call)
{
	stream << "Option price: " << Call.PriceByBSFormula << endl;
	stream << "Delta: " << Call.DeltaByBSFormula << endl;
	stream << "Gamma: " << Call.GammaByBSFormula << endl;
	stream << "Theta: " << Call.ThetaByBSFormula << endl;

	return stream;
}

ostream& operator<<(ostream& stream, EurPut &Put)
{
	stream << "Option price: " << Put.PriceByBSFormula << endl;
	stream << "Delta: " << Put.DeltaByBSFormula << endl;
	stream << "Gamma: " << Put.GammaByBSFormula << endl;
	stream << "Theta: " << Put.ThetaByBSFormula << endl;

	return stream;
}