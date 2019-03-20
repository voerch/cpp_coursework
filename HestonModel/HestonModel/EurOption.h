#ifndef EurOption_h
#define EurOption_h

#include "HestonModel.h"

class EurOption
{
   public:
      double T;
      int m;
      double PriceByMC(HestonModel Model, long N, double epsilon);
	  //double VegaByMC(HestonModel Model, long N, double epsilon);
	  double Vega, Price;
      virtual double Payoff(SamplePath& S)=0;
};


class CallOption : public EurOption
{
	public:
		double K;
		CallOption(double T_, double K_, int m_)
		{
			T = T_;  K = K_; m = m_;
		}
		double Payoff(SamplePath& S);
};




#endif
