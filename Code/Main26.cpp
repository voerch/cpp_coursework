#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "HeatEq.h"
#include "CNMethod.h"

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T=1./12., K=100.0, zl=1.0, zu=2.0*S0;
   Put EuropeanPut(K,T,zl,zu);

   int imax=200, jmax=2000;

   HeatEq HeatPDE(&Model,&EuropeanPut);

   CNMethod Method(&HeatPDE, imax, jmax);
   Method.SolvePDE();

   double t=0.0;
   double z=S0;

   double x=HeatPDE.X(t,z);
   cout << "Price = " << HeatPDE.U(t,Method.v(t,x)) << endl;

   return 0;
}
