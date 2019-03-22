#ifndef Exe6_8_HeatEqLCP_h
#define Exe6_8_HeatEqLCP_h

#include "LCP.h"
#include "BSModel01.h"
#include "Option.h"
#include "HeatEq.h"

class HeatEqLCP: public LCP, public HeatEq
{
   public:
      HeatEqLCP(BSModel* PtrModel,Option* PtrOption)
         : HeatEq(PtrModel,PtrOption){PtrPDE = this;}

      double g(double t,double x)
         {return V(t,PtrOption->Payoff(Z(t,x)));}
};

#endif
