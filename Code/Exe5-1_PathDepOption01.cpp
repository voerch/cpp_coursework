#include "Exe5-1_PathDepOption01.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel Model, long N)
{
   double H=0.0;
   SamplePath S(m);
   for(long i=0; i<N; i++)
   {
      Model.GenerateSamplePath(T,m,S);
      H = (i*H + Payoff(S))/(i+1.0);
   }
   return exp(-Model.r*T)*H;
}

double ArthmAsianCall::Payoff(SamplePath& S)
{
   double Ave=0.0;
   for (int k=0; k<m; k++) Ave=(k*Ave+S[k])/(k+1.0);
   if (Ave<K) return 0.0;
   return Ave-K;
}

double EurCall::Payoff(SamplePath& S)
{
   if (S[0]<K) return 0.0;
   return S[0]-K;
}

double EurPut::Payoff(SamplePath& S)
{
   if (K<S[0]) return 0.0;
   return K-S[0];
}

