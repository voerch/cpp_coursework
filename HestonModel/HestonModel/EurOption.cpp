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
	Stats1 Del;
	Stats1 Gam;
	SamplePath S(m);

	for (long i = 0; i<N; i++)
	{
		Model.GenerateSamplePath(T, m, S);
		Acc.add(Payoff(S));
		Rescale(S, 1+epsilon);
		Del.add(Payoff(S));
		Rescale(S, (1 - epsilon)/(1 + epsilon));
		Gam.add(Payoff(S));
	}
	
	double Price = exp(-Model.r*T)*Acc.mean();
	double PriceError = (exp(-Model.r*T) * Acc.stdevP()) / sqrt(N - 1.0) / Price;
	double Delta = exp(-Model.r*T)*(Del.mean() - Acc.mean())/(Model.S0 * epsilon);
	double DeltaError = exp(-Model.r*T) * (Del.stdevP() - Acc.stdevP()) / sqrt(N - 1.0) / Delta;
	double Gamma = exp(-Model.r*T) * (Del.mean() - (2 * Acc.mean()) + Gam.mean()) / pow(Model.S0 * epsilon, 2);
	double GammaError = exp(-Model.r*T) * (Del.stdevP() - (2 * Acc.stdevP()) + Gam.stdevP()) / sqrt(N - 1.0) / Delta;
	
	cout << "Price:" << Price << " +/- " << PriceError << endl;
	cout << "Delta:" << Delta << " +/- " << DeltaError << endl;
	cout << "Gamma:" << Gamma << " +/- " << DeltaError << endl;
	
	return Price;;
}

