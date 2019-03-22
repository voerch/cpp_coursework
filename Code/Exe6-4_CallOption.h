#ifndef Exe6_4_CallOption_h
#define Exe6_4_CallOption_h

#include "Option.h"

class Call: public Option
{
   public:
      double K;
      Call(double K_, double T_, double zl_, double zu_)
         {K=K_; T=T_; zl=zl_; zu=zu_;}
      double Payoff(double z);
      double UpperBdCond(BSModel* PtrModel, double t);
      double LowerBdCond(BSModel* PtrModel, double t);
};

#endif
