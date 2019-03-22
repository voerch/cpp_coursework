#ifndef CNMethod_h
#define CNMethod_h

#include "ImplicitScheme.h"

class CNMethod: public ImplicitScheme
{
   public:
      CNMethod(ParabPDE* PtrPDE_,int imax_,int jmax_)
         : ImplicitScheme(PtrPDE_, imax_, jmax_) {}

      double A(int i, int j)
         {return 0.5*dt*(b(i-0.5,j)/2.0-a(i-0.5,j)/dx)/dx;}
      double B(int i, int j)
         {return 1.0+0.5*dt*(2.0*a(i-0.5,j)/(dx*dx)-c(i-0.5,j));}
      double C(int i, int j)
         {return -0.5*dt*(b(i-0.5,j)/2.0+a(i-0.5,j)/dx)/dx;}
      double D(int i, int j){return -dt*d(i-0.5,j);}
      double E(int i, int j){return -A(i,j);}
      double F(int i, int j){return 2.0-B(i,j);}
      double G(int i, int j){return -C(i,j);}
};

#endif
