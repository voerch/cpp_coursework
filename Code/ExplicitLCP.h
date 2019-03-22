#ifndef ExplicitLCP_h
#define ExplicitLCP_h

#include "LCP.h"
#include "FDLCP.h"
#include "ExplicitMethod.h"

class ExplicitLCP: public ExplicitMethod, public FDLCP
{
   public:
      ExplicitLCP(LCP* PtrLCP_, int imax_, int jmax_)
         : ExplicitMethod(PtrLCP_->PtrPDE, imax_, jmax_)
      {
         PtrLCP = PtrLCP_;
         PtrFDMethod = this;
      }

      void SolveLCP();
};

#endif
