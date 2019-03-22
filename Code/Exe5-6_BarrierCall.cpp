#include "Exe5-6_BarrierCall.h"

double BarrierCall::Payoff(SamplePath& S)
{
   for (int k=0; k<m; k++)
   {
      if (S[k]>L) return 0.0;
   }
   if (S[m-1]<K) return 0.0;
   return S[m-1]-K;
}


