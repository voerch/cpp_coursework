#ifndef PathDepOption01_h
#define PathDepOption01_h

#include "BSModel01.h"

class PathDepOption
{
   public:
      double T;
      int m;
      double PriceByMC(BSModel Model, long N);
	  double Delta(BSModel Model);
      virtual double Payoff(SamplePath& S)=0;
};


class AccrualNote : public PathDepOption
{
public:
	double K_Min, Principal,K_Max;
	AccrualNote(double T_, double K_mi, double K_ma, int m_, double Principal_)
	{
		T = T_; K_Min = K_mi; K_Max = K_ma; m = m_; Principal = Principal_;
	}
	double Payoff(SamplePath& S);
};

#endif
