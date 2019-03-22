#include "EurOption.h"
#include <cmath>
#include "stats.h"
#include <algorithm>

double CallOption::Payoff(SamplePath& S)
{
	if (S.back() - K > 0)
		return (S.back() - K);
	else
		return 0;
}

void Rescale(SamplePath& S, double x)
{
	int s_Size = S.size();
	for (int j = 0; j < s_Size; j++)
		S[j] = x * S[j];
}

double EurOption::PriceByMC(HestonModel Model, long N, double epsilon)
{
	Stats1 Acc;
	SamplePath S(m);
	SamplePath Vol(m);

	for (long i = 0; i<N; i++)
	{
		Model.GenerateSamplePath(T, m, S, Vol);
		Acc.add(Payoff(S));
	}
	
	Price = exp(-Model.r*T)*Acc.mean();
	PriceError = (exp(-Model.r*T) * Acc.stdevP()) / sqrt(N - 1.0);
	

	return Price;
}

double EurOption::VolatilitySmile(HestonModel Model, long N, double epsilon, SamplePath S)
{
	Stats1 Acc;

	for (long i = 0; i<N; i++)
	{
		Acc.add(Payoff(S));
	}

	Price = exp(-Model.r*T)*Acc.mean();
	PriceError = (exp(-Model.r*T) * Acc.stdevP()) / sqrt(N - 1.0);

	return Price;
}

double N(double x)
{
	return 0.5 * erfc(-x * sqrt(0.5));
}

double CallOption::d_plus(double S0, double sigma, double r)
{
	return (log(S0 / K) +
		(r + 0.5*pow(sigma, 2.0))*T)
		/ (sigma*sqrt(T));
}

double CallOption::d_minus(double S0, double sigma, double r)
{
	return d_plus(S0, sigma, r) - sigma*sqrt(T);
}

double CallOption::PriceByBSFormula(double S0, double sigma, double r)
{
	return S0*N(d_plus(S0, sigma, r))- K*exp(-r*T)*N(d_minus(S0, sigma, r));
}
