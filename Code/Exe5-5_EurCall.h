#ifndef Exe5_5_EurCall_h
#define Exe5_5_EurCall_h

#include "BSModel01.h"

class EurCall
{
   public:
      double T, K;
      EurCall(double T_, double K_){T=T_; K=K_;}
      double d_plus(double S0, double sigma, double r);
      double d_minus(double S0, double sigma, double r);
      double PriceByBSFormula(double S0,                   
         double sigma, double r);
      double VegaByBSFormula(double S0,                    
         double sigma, double r);
      double DeltaByBSFormula(double S0,             
         double sigma, double r);
};

#endif

