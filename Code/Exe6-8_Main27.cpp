#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "Exe6-8_HeatEqLCP.h"
#include "ExplicitLCP.h"

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double K=100.0, T=1./12., zl=1.0, zu=2.0*S0;
   Put PutOption(K,T,zl,zu);

   HeatEqLCP HeatLCP(&Model,&PutOption);

   int imax=3000, jmax=1000;
   ExplicitLCP Method(&HeatLCP, imax, jmax);

   Method.SolveLCP();

   double t=0.0;
   double z=S0;
   double x=HeatLCP.X(t,z);
   cout << "Am  Put Price = " << HeatLCP.U(t,Method.v(t,x)) << endl;

   Method.SolvePDE();
   cout << "Eur Put Price = " << HeatLCP.U(t,Method.v(t,x)) << endl;

   return 0;
}
