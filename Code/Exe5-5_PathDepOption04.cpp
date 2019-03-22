#include "Exe5-5_PathDepOption04.h"
#include <cmath>

void Rescale(SamplePath& S, double epsilon)
{
   int m=S.size();
   for (int j=0; j<m; j++) S[j] = (1.0+epsilon)*S[j];
}

double PathDepOption::PriceByMC(BSModel Model, long N, double epsilon)
{
   double H=0.0, Hsq=0.0, Heps=0.0;
   SamplePath S(m);
   for(long i=0; i<N; i++)
   {
      Model.GenerateSamplePath(T,m,S);
      H = (i*H + Payoff(S))/(i+1.0);
      Hsq = (i*Hsq + pow(Payoff(S),2.0))/(i+1.0);
      Rescale(S,epsilon);
      Heps = (i*Heps + Payoff(S))/(i+1.0);
   }
   Price = exp(-Model.r*T)*H;
   PricingError = exp(-Model.r*T)*sqrt(Hsq-H*H)/sqrt(N-1.0);
   delta = exp(-Model.r*T)*(Heps-H)/(Model.S0*epsilon);
   return Price;
}

double PathDepOption::PriceByVarRedMC
       (BSModel Model, long N, PathDepOption& CVOption, double epsilon)
{
   DifferenceOfOptions VarRedOpt(T,m,this,&CVOption);

   Price = VarRedOpt.PriceByMC(Model,N,epsilon)
           + CVOption.PriceByBSFormula(Model);

   delta = VarRedOpt.delta + CVOption.DeltaByBSFormula(Model);

   PricingError = VarRedOpt.PricingError;

   return Price;
}

double ArthmAsianCall::Payoff(SamplePath& S)
{
   double Ave=0.0;
   for (int k=0; k<m; k++) Ave=(k*Ave+S[k])/(k+1.0);
   if (Ave<K) return 0.0;
   return Ave-K;
}


