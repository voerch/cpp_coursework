#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "BSEqLCP.h"
#include "ExplicitLCP.h"

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double K=100.0, T=1./12., zl=0.0, zu=2.0*S0;
   Put PutOption(K,T,zl,zu);

   BSEqLCP BSLCP(&Model,&PutOption);

   int imax=3000, jmax=1000;
   ExplicitLCP Method(&BSLCP, imax, jmax);

   Method.SolveLCP();
   cout << "Am  Put Price = " << Method.v(0.0,S0) << endl;

   Method.SolvePDE();
   cout << "Eur Put Price = " << Method.v(0.0,S0) << endl;

   return 0;
}
