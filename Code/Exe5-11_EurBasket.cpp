#include "Exe5-11_EurBasket.h"

double EurBasketCall::Payoff(SamplePath& S)
{
   double Sum=0.0;
   int d=S[0].size();
   for (int i=0; i<d; i++) Sum=Sum+S[0][i];
   if (Sum<K) return 0.0;
   return Sum-K;
}

