#ifndef Exe511SumOfCalls_h
#define Exe511SumOfCalls_h

#include "Exe5-11_PathDepOption05.h"

class SumOfCalls: public PathDepOption
{
   public:
      Vector K;
      SumOfCalls(double T_, Vector K_){T=T_; K=K_; m=1;}
      double Payoff(SamplePath& S);
      double PriceByBSFormula(BSModel Model);
};

#endif
