#ifndef Exe3_2_BSModel_h
#define Exe3_2_BSModel_h

#include "Exe3-2_BinModel02.h"
#include <cmath>
using namespace std;

class BSModel
{
   private:
      double S0, r, sigma;
   public:
      BSModel(double S0_, double r_, double sigma_)
         {S0 = S0_; r = r_; sigma = sigma_;}
      BinModel ApproxBinModel(double h)
      {
         double U=exp((r-sigma*sigma/2)*h+sigma*sqrt(h))-1;
         double D=exp((r-sigma*sigma/2)*h-sigma*sqrt(h))-1;
         double R=exp(r*h)-1;
         BinModel ApproxModel(S0,U,D,R);
         return ApproxModel;
      }
};

#endif
