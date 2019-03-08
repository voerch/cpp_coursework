#include "PathDepOption01.h"
#include <cmath>
#include "stats.h"

double AccrualNote::Payoff(SamplePath& S)
{
	double d=0;
	for (int k = 0; k < m; k++) 
	{
		if ((S[k] < K_Max) && (S[k] > K_Min)) 
			d++;
	}
	return  (d/m)*Principal;
}

double PathDepOption::PriceByMC(BSModel Model, long N)
{
	Stats1 Acc;
	SamplePath S(m);
	for (long i = 0; i<N; i++)
	{
		Model.GenerateSamplePath(T, m, S);
		Acc.add(Payoff(S));
	}
	cout << (exp(-Model.r*T) * Acc.stdevP()) / sqrt(N - 1) << endl;
	return exp(-Model.r*T)*Acc.mean();
}

//double PathDepOption::Delta(BSModel Model)
//{
//	double epsilon = 0.005;
//	Stats1 Acc;
//	SamplePath S(m);
//	for (long i = 0; i<100; i++)
//	{
//		Model.GenerateSamplePath(T, m, S);
//		Acc.add((Payoff(S) - Payoff(S))/(epsilon*S));
//	}
//	cout << (exp(-Model.r*T) * Acc.stdevP()) / sqrt(N - 1) << endl;
//	return exp(-Model.r*T)*Acc.mean();
//
//}