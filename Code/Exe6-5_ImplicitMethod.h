#ifndef Exe6_5_ImplicitMethod_h
#define Exe6_5_ImplicitMethod_h

#include "ImplicitScheme.h"

class ImplicitMethod: public ImplicitScheme
{
   public:
      ImplicitMethod(ParabPDE* PtrPDE_,int imax_,int jmax_)// !h%1@
         : ImplicitScheme(PtrPDE_, imax_, jmax_) {}

      double A(int i, int j){return 0.0;}
      double B(int i, int j){return 1.0;}
      double C(int i, int j){return 0.0;}
      double D(int i, int j){return -dt*d(i-1,j);}
      double E(int i, int j){return -dt*(b(i-1,j)/2.0-a(i-1,j)/dx)/dx;}
      double F(int i, int j){return 1.0+dt*c(i-1,j)-2.0*dt*a(i-1,j)/(dx*dx);}
      double G(int i, int j){return  dt*(b(i-1,j)/2.0+a(i-1,j)/dx)/dx;}
};

#endif
