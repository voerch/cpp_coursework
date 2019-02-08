#include "UpAndOutEurCall.h"
#include <cmath>
#include <vector>

using namespace std;

double N(double x)
{
	double gamma = 0.2316419;     double a1 = 0.319381530;
	double a2 = -0.356563782;   double a3 = 1.781477937;
	double a4 = -1.821255978;   double a5 = 1.330274429;
	double pi = 4.0*atan(1.0); double k = 1.0 / (1.0 + gamma*x);
	if (x >= 0.0)
	{
		return 1.0 - ((((a5*k + a4)*k + a3)*k + a2)*k + a1)*k*exp(-x*x / 2.0) / sqrt(2.0*pi);
	}
	else return 1.0 - N(-x);
}

double UpAndOutEurCall::D(double x, double r, double sigma, double T)
{
	return ((log(x) + ((r + (0.5*pow(sigma, 2)))*T)) / (sigma*sqrt(T)));
}

double UpAndOutEurCall::PriceByBSFormula(double S0, double B, double sigma, double r)
{
	double d1 = D(S0/K, r, sigma, T);					double d2 = d1 - (sigma*sqrt(T));
	double d3 = D(S0/B, r, sigma, T);					double d4 = d3 - (sigma*sqrt(T));
	double d5 = D(S0/B, -r, sigma, T);					double d6 = d5 - (sigma*sqrt(T));
	double d7 = D((S0*K)/pow(B, 2), -r, sigma, T);		double d8 = d7 - (sigma*sqrt(T));

	double FirstTerm = S0*(N(d1) - N(d3) - (pow(B / S0, 1 + (2 * r / pow(sigma, 2)))*(N(d6) - N(d8))));
	double SecondTerm = K*exp(-r*T)*(N(d2) - N(d4) - (pow(B / S0, -1 + (2 * r / pow(sigma, 2))) * (N(d5) - N(d7))));
	
	return (FirstTerm - SecondTerm);
}

double UpAndOutEurCall::PriceByCRR(double N, double S0, double B, double sigma, double r)
{
	double TimeStep = T / N;
	double R = exp(r*TimeStep) - 1;
	double u = exp(((r - (pow(sigma, 2) / 2))*TimeStep) + (sigma*sqrt(TimeStep)));
	double d = exp(((r - (pow(sigma, 2) / 2))*TimeStep) - (sigma*sqrt(TimeStep)));

	double q = (1 + R - d) / (u - d);
	vector<double> Price(N + 1);

	for (int i = 0; i <= N; i++)
	{
		double S = S0*pow(u, i)*pow(d, N - i);
		double Payoff;
		
		if (S > B)
			Payoff = 0.0;
		else if (S > K)
			Payoff = S - K;
		else
			Payoff = 0.0;

		Price[i] = Payoff;
	}

	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			Price[i] = ((q * Price[i + 1]) + ((1 - q)*Price[i])) / (1+R);
			if (Price[i] > B)
				Price[i] = 0;
		}
	}

	return Price[0];
}