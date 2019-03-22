#ifndef Exe5_6_EurCall_h
#define Exe5_6_EurCall_h

#include "BSModel01.h"
#include "Exe5-6_PathDepOption04.h"

class EurCall: public PathDepOption
{
   public:
      double T, K;
      EurCall(double T_, double K_){T=T_; K=K_;m=1;}
      EurCall(double T_, double K_, int m_){T=T_; K=K_;m=m_;}
      double d_plus(double S0, double sigma, double r);
      double d_minus(double S0, double sigma, double r);
      double PriceByBSFormula(double S0,
         double sigma, double r);
      double VegaByBSFormula(double S0,
         double sigma, double r);
      double DeltaByBSFormula(double S0,
         double sigma, double r);
      double PriceByBSFormula(BSModel Model);
      double DeltaByBSFormula(BSModel Model);
      double Payoff(SamplePath& S);
};

#endif

