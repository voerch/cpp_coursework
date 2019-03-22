#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "Exe6-7_FiniteDomainEq.h"
#include "CNMethod.h"

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T=1./12., K=100.0, zl=0.0, zu=2.0*S0;
   Put EuropeanPut(K,T,zl,zu);

   int imax=200, jmax=2000;

   double L=S0;
   FiniteDomainEq FiniteDomainPDE(&Model,&EuropeanPut,L);

   CNMethod Method(&FiniteDomainPDE, imax, jmax);
   Method.SolvePDE();

   double t=0.0;
   double z=S0;

   double x=FiniteDomainPDE.X(z);
   cout << "Price = " << FiniteDomainPDE.U(x,Method.v(t,x)) << endl;

   return 0;
}
