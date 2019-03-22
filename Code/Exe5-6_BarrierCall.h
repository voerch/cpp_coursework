#ifndef Exe5_6_BarrierCall_h
#define Exe5_6_BarrierCall_h

#include "Exe5-6_PathDepOption04.h"

class BarrierCall: public PathDepOption
{
   public:
      double K,L;
      BarrierCall(double T_, double K_, double L_, int m_)
            {T=T_; K=K_; L=L_; m=m_;}
      double Payoff(SamplePath& S);
};

#endif

