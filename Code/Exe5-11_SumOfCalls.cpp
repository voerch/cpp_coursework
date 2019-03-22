#include "Exe5-11_SumOfCalls.h"
#include "EurCall.h"

double SumOfCalls::Payoff(SamplePath& S)
{
   int d = S[0].size();
   double Sum=0.0;
   for (int j=0; j<d; j++)
   {
      if (S[0][j]>K[j]) Sum = Sum+S[0][j]-K[j];
   }
   return Sum;
}

double SumOfCalls::PriceByBSFormula(BSModel Model)
{
   int d = Model.S0.size();
   double Sum=0.0;
   for (int j=0;j<d;j++)
   {
      EurCall Option(T,K[j]);
      Sum=Sum+Option.PriceByBSFormula(Model.S0[j],Model.sigma[j],Model.r);
   }
   return Sum;
}

