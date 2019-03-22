#include <cmath>
#include "Exe5-7_ContGmtrAsianCall.h"
#include "EurCall.h"

double ContGmtrAsianCall::Payoff(SamplePath& S)
{
   double Ave=0.0;
   for (int k=0; k<m; k++)
   {
      Ave=(k*Ave+log(S[k]))/(k+1.0);
   }
   Ave = exp(Ave);
   if (Ave<K) return 0.0;
   return Ave-K;
}

double ContGmtrAsianCall::PriceByBSFormula(BSModel Model)
{
   double c1 = Model.S0*exp(-0.5*(Model.r+Model.sigma*Model.sigma/6.0)*T);
   double c2 = Model.sigma/sqrt(3.0);
   EurCall G(T, K);
   Price = G.PriceByBSFormula(c1,c2,Model.r);
   return Price;
}
