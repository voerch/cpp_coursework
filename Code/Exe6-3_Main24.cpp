#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "BSEq.h"
#include "ExplicitMethod.h"

double x(FDMethod* Method, double t, double S)
{
   return (Method->v(t,S+Method->dx)-Method->v(t,S-Method->dx))
            /(2.0*Method->dx);
}

double y(FDMethod* Method, double t, double S)
{
   return Method->v(t,S)-x(Method,t,S)*S;
}

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double K=100.0, T=1./12., zl=0.0, zu=2.0*S0;
   Put EuropeanPut(K,T,zl,zu);

   BSEq BSPDE(&Model,&EuropeanPut);

   int imax=3000, jmax=1000;
   ExplicitMethod Method(&BSPDE, imax, jmax);

   Method.SolvePDE();

   double t=0.0, S=100.0;

   cout << "S = " << S << ", t = " << t << endl<< endl;
   cout << "Price = " << Method.v(t,S) << endl << endl;
   cout << "Strategy:" << endl
      << "  number of stocks         = " << x(&Method,t,S) << endl
      << "  money invested risk free = " << y(&Method,t,S) << endl << endl;

   return 0;
}
