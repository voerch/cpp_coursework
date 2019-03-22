#ifndef BSEqLCP_h
#define BSEqLCP_h

#include "LCP.h"
#include "BSModel01.h"
#include "Option.h"
#include "BSEq.h"

class BSEqLCP: public LCP, public BSEq
{
   public:
      BSEqLCP(BSModel* PtrModel,Option* PtrOption)
         : BSEq(PtrModel,PtrOption){PtrPDE = this;}

      double g(double t,double z)
         {return PtrOption->Payoff(z);}
};

#endif
