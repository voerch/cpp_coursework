#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "BSEqLCP.h"
#include "ExplicitLCP.h"

int ExercisePolicy(FDMethod* PtrMethod,LCP* PtrLCP,double t,double S)
{
   if (PtrMethod->v(t,S) > PtrLCP->g(t,S)) return 0;
   return 1;
}

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double K=100.0, T=1./12., zl=0.0, zu=2.0*S0;
   Put PutOption(K,T,zl,zu);

   BSEqLCP BSLCP(&Model,&PutOption);

   int imax=3000, jmax=1000;
   ExplicitLCP Method(&BSLCP, imax, jmax);

   double t=0.5*T;
   double S=90;

   Method.SolveLCP();
   cout << "Am  Put Price at time " <<t<< " given that S=" <<S<< " is: " << Method.v(t,S) << endl;

   Method.SolvePDE();
   cout << "Eur Put Price at time " <<t<< " given that S=" <<S<< " is: " << Method.v(t,S) << endl;


   if (ExercisePolicy(&Method,&BSLCP,t,S)==1)
      cout << "we should exercise the American option" << endl;

   return 0;
}
