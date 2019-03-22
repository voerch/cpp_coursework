#ifndef Exe511EurBasket_h
#define Exe511EurBasket_h

#include "Exe5-11_PathDepOption05.h"

class EurBasketCall: public PathDepOption
{
   public:
      double K;
      EurBasketCall(double T_, double K_)
            {T=T_; K=K_; m=1;}
      double Payoff(SamplePath& S);
};

#endif
