#ifndef Exe5_5_GmtrAsianCall_h
#define Exe5_5_GmtrAsianCall_h

#include "Exe5-5_PathDepOption04.h"

class GmtrAsianCall: public PathDepOption
{
   public:
      double K;
      GmtrAsianCall(double T_, double K_, int m_)
            {T=T_; K=K_; m=m_;}
      double Payoff(SamplePath& S);
      double PriceByBSFormula(BSModel Model);
      double DeltaByBSFormula(BSModel Model);
};

#endif

