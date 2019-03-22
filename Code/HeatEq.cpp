#include "HeatEq.h"
#include <cmath>

HeatEq::HeatEq
(BSModel* PtrModel_,Option* PtrOption_)
{
   PtrModel=PtrModel_; PtrOption=PtrOption_;
   T=PtrOption->T;
   xl=X(0.0,PtrOption->zl);
   xu=X(0.0,PtrOption->zu);
}

double HeatEq::f(double x)
{
   return V(T,PtrOption->Payoff(Z(T,x)));
}

double HeatEq::fl(double t)
{
   return V(t,PtrOption->LowerBdCond(PtrModel,t));
}

double HeatEq::fu(double t)
{
   return V(t,PtrOption->UpperBdCond(PtrModel,t));
}

double HeatEq::Z(double t,double x)
{
   double r=PtrModel->r;
   double sigma=PtrModel->sigma;
   double S0=PtrModel->S0;
   return S0*exp((r-0.5*sigma*sigma)*t+sigma*x);
}

double HeatEq::V(double t,double u)
{
   return exp(-PtrModel->r*t)*u;
}

double HeatEq::X(double t,double z)
{
   double r=PtrModel->r;
   double sigma=PtrModel->sigma;
   double S0=PtrModel->S0;
   return (log(z/S0)-(r-0.5*sigma*sigma)*t)/sigma;
}

double HeatEq::U(double t,double v)
{
   return exp(PtrModel->r*t)*v;
}
