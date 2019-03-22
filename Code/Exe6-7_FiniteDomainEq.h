#ifndef Exe6_7_FiniteDomainEq_h
#define Exe6_7_FiniteDomainEq_h

#include "BSModel01.h"
#include "Option.h"
#include "ParabPDE.h"

class FiniteDomainEq: public ParabPDE
{
   public:
      double L;
      BSModel* PtrModel;
      Option* PtrOption;
      FiniteDomainEq(BSModel* PtrModel_,Option* PtrOption_,double L_);

      double a(double t,double x)
      {return -0.5*PtrModel->sigma*PtrModel->sigma*x*x*(1.0-x)*(1.0-x);}
      double b(double t,double x){return -PtrModel->r*x*(1.0-x);}
      double c(double t,double x){return PtrModel->r*(1.0-x);}
      double d(double t,double x){return 0.0;}

      double f(double x);
      double fl(double t);
      double fu(double t);

      double Z(double x);
      double V(double z,double u);
      double X(double z);
      double U(double z,double v);
};

#endif
