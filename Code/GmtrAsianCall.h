#ifndef GmtrAsianCall_h
#define GmtrAsianCall_h

#include "PathDepOption04.h"

class GmtrAsianCall: public PathDepOption
{
   public:
      double K;
      GmtrAsianCall(double T_, double K_, int m_)
            {T=T_; K=K_; m=m_;}
      double Payoff(SamplePath& S);
      double PriceByBSFormula(BSModel Model);
};

#endif
