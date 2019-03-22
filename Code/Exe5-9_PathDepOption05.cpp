#include "Exe5-9_PathDepOption05.h"
#include <cmath>

void Rescale(SamplePath& S, double x, int j)
{
   int m=S.size();
   for (int k=0;k<m;k++) S[k][j] = x*S[k][j];
}

double PathDepOption::PriceByMC(BSModel Model, long N, double epsilon)
{
   double H=0.0;
   SamplePath S(m);

   int d = Model.S0.size();
   delta.resize(d);

   Vector Heps(d);
   for (int i=0;i<d;i++) Heps[i]=0.0;

   for(long i=0; i<N; i++)
   {
      Model.GenerateSamplePath(T,m,S);
      H = (i*H + Payoff(S))/(i+1.0);

      for(int j=0;j<d;j++)
      {
         Rescale(S,1.0+epsilon,j);
         Heps[j] = (i*Heps[j] + Payoff(S))/(i+1.0);
         if (j<d-1) Rescale(S,1.0/(1.0+epsilon),j);
      }
   }
   Price = exp(-Model.r*T)*H;
   for (int j=0;j<d;j++) delta[j] = exp(-Model.r*T)*(Heps[j]-H)/(epsilon*Model.S0[j]);
   return Price;
}

double ArthmAsianCall::Payoff(SamplePath& S)
{
   double Ave=0.0;
   int d=S[0].size();
   Vector one(d);
   for (int i=0; i<d; i++) one[i]=1.0;
   for (int k=0; k<m; k++)
   {
      Ave=(k*Ave+(one^S[k]))/(k+1.0);
   }
   if (Ave<K) return 0.0;
   return Ave-K;
}
