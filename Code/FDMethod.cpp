#include "FDMethod.h"

FDMethod::FDMethod(ParabPDE* PtrPDE_, int imax_, int jmax_)
{
   PtrPDE=PtrPDE_;
   imax=imax_; jmax=jmax_;
   dx=(PtrPDE->xu - PtrPDE->xl)/jmax;
   dt=PtrPDE->T/imax;
   V.resize(imax+1);
   for (int i=0; i<=imax; i++) V[i].resize(jmax+1);
}

double FDMethod::v(double t,double x)
{
   int i = (int)(t/dt);
   int j = (int)((x-PtrPDE->xl)/dx);
   double l1 = (t-FDMethod::t(i))/dt, l0 = 1.0-l1;
   double w1 = (x-FDMethod::x(j))/dx, w0 = 1.0-w1;
   return l1*w1*V[i+1][j+1] + l1*w0*V[i+1][j]
         +l0*w1*V[ i ][j+1] + l0*w0*V[ i ][j];
}
