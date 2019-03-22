#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "Exe6-2_CallOption.h"
#include "BSEq.h"
#include "ExplicitMethod.h"

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double K=100.0, T=1./12., zl=0.0, zu=2.0*S0;
   Put EuropeanPut(K,T,zl,zu);
   Call EuropeanCall(K,T,zl,zu);

   BSEq BSPDE(&Model,&EuropeanPut);
   BSEq BSPDE2(&Model,&EuropeanCall);

   int imax=5000, jmax=1000;
   ExplicitMethod Method(&BSPDE, imax, jmax);
   ExplicitMethod Method2(&BSPDE2, imax, jmax);

   Method.SolvePDE();
   Method2.SolvePDE();

   cout << "Put  Price = " << Method.v(0.0,S0) << endl;
   cout << "Call Price = " << Method2.v(0.0,S0) << endl;

   return 0;
}

