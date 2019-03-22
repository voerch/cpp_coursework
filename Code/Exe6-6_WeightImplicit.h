#ifndef Exe6_6_WeightImplicit_h
#define Exe6_6_WeightImplicit_h

#include "ImplicitScheme.h"

class WeightImplicit: public ImplicitScheme
{
   public:
      double lambda;
      WeightImplicit(ParabPDE* PtrPDE_,int imax_,int jmax_,double lambda_)
         : ImplicitScheme(PtrPDE_, imax_, jmax_) {lambda=lambda_;}

      double A(int i, int j)
         {return (1.0-lambda)*dt*(b(i-lambda,j)/2.0-a(i-lambda,j)/dx)/dx;}
      double B(int i, int j)
         {return 1.0+(1.0-lambda)*dt*(2.0*a(i-lambda,j)/(dx*dx)-c(i-lambda,j));}
      double C(int i, int j)
         {return -(1.0-lambda)*dt*(b(i-lambda,j)/2.0+a(i-lambda,j)/dx)/dx;}

      double D(int i, int j){return -dt*d(i-lambda,j);}

      double E(int i, int j)
         {return -lambda*dt*(b(i-lambda,j)/2.0-a(i-lambda,j)/dx)/dx;}
      double F(int i, int j)
         {return 1.0-lambda*dt*(2.0*a(i-lambda,j)/(dx*dx)-c(i-lambda,j));}
      double G(int i, int j)
         {return lambda*dt*(b(i-lambda,j)/2.0+a(i-lambda,j)/dx)/dx;}
};

#endif

