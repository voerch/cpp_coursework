#ifndef Exe5_10_EurBasket_h
#define Exe5_10_EurBasket_h

#include "PathDepOption05.h"

class EurBasketCall: public PathDepOption
{
   public:
      double K;
      EurBasketCall(double T_, double K_)
            {T=T_; K=K_; m=1;}
      double Payoff(SamplePath& S);
};

#endif
