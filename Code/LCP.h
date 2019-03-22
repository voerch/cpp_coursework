#ifndef LCP_h
#define LCP_h

#include "ParabPDE.h"

class LCP
{
   public:
      ParabPDE* PtrPDE;
      virtual double g(double t,double x)=0;
};

#endif
