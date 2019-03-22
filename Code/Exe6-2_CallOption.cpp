#include "Exe6-2_CallOption.h"
#include <cmath>

double Call::Payoff(double z)
{
   if (z<K) return 0.0;
   return z-K;
}

double Call::UpperBdCond(BSModel* PtrModel, double t)
{
   return zu-K*exp(-PtrModel->r*(T-t));
}

double Call::LowerBdCond(BSModel* PtrModel, double t)
{
   return zl;
}
