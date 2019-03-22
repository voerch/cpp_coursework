#ifndef Exe5_1_PathDepOption01_h
#define Exe5_1_PathDepOption01_h

#include "BSModel01.h"

class PathDepOption
{
   public:
      double T;
      int m;
      double PriceByMC(BSModel Model, long N);
      virtual double Payoff(SamplePath& S)=0;
};

class ArthmAsianCall: public PathDepOption
{
   public:
      double K;
      ArthmAsianCall(double T_, double K_, int m_)
            {T=T_; K=K_; m=m_;}
      double Payoff(SamplePath& S);
};

class EurCall: public PathDepOption
{
   public:
      double K;
      EurCall(double T_, double K_)
            {T=T_; K=K_; m=1;}
      double Payoff(SamplePath& S);
};

class EurPut: public PathDepOption
{
   public:
      double K;
      EurPut(double T_, double K_)
            {T=T_; K=K_; m=1;}
      double Payoff(SamplePath& S);
};

#endif
