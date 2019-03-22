#include "Exe6-7_FiniteDomainEq.h"
#include <cmath>
#include <iostream>
using namespace std;

FiniteDomainEq::FiniteDomainEq
(BSModel* PtrModel_,Option* PtrOption_,double L_)
{
   L=L_;
   PtrModel=PtrModel_; PtrOption=PtrOption_;
   T=PtrOption->T;
   xl=X(PtrOption->zl);
   xu=X(PtrOption->zu);
}

double FiniteDomainEq::f(double x)
{
   return V(Z(x),PtrOption->Payoff(Z(x)));
}

double FiniteDomainEq::fl(double t)
{
   return V(PtrOption->zl,PtrOption->LowerBdCond(PtrModel,t));
}

double FiniteDomainEq::fu(double t)
{
   return V(PtrOption->zu,PtrOption->UpperBdCond(PtrModel,t));
}

double FiniteDomainEq::Z(double x)
{
   return L*x/(1.0-x);
}

double FiniteDomainEq::V(double z,double u)
{
   return u/(z+L);
}

double FiniteDomainEq::X(double z)
{
   return z/(L+z);
}

double FiniteDomainEq::U(double x,double v)
{
   return L*v/(1.0-x);
}
