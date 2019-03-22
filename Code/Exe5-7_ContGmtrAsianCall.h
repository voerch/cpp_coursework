#ifndef Exe5_7_ContGmtrAsianCall_h
#define Exe5_7_ContGmtrAsianCall_h

#include "PathDepOption04.h"

class ContGmtrAsianCall: public PathDepOption
{
   public:
      double K;
      ContGmtrAsianCall(double T_, double K_, int m_)
            {T=T_; K=K_; m=m_;}
      double Payoff(SamplePath& S);
      double PriceByBSFormula(BSModel Model);
};

#endif
