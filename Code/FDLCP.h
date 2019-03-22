#ifndef FDLCP_h
#define FDLCP_h

#include "FDMethod.h"
#include "LCP.h"

class FDLCP
{
   public:
      LCP* PtrLCP;
      FDMethod* PtrFDMethod;
      double g(int i,int j)
      {
         return PtrLCP->g(PtrFDMethod->t(i),PtrFDMethod->x(j));
      }
};

#endif
