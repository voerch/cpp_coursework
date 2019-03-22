#ifndef EurOption_h
#define EurOption_h

#include "HestonModel.h"
#include "stats.h"

class EurOption
{
   public:
      double T;
      int m;
      double PriceByMC(HestonModel Model, long N, double epsilon);
	  double VolatilitySmile(HestonModel Model, long N, double epsilon, SamplePath S);
	  double PriceError, Price;
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
		
		double d_minus(double S0, double sigma, double r);
		double PriceByBSFormula(double S0, double sigma, double r);
		double d_plus(double S0, double sigma, double r);

};

class Intermediary : public CallOption
{
private:
	double S0, r;

public:
	Intermediary(double T_, double K_, int m_, double S0_, double r_) :CallOption(T_, K_, m_)
	{
		S0 = S0_;
		r = r_;
	}

	double Value(double sigma)
	{
		return PriceByBSFormula(S0, sigma, r);
	}
	double Deriv(double sigma)
	{
		return 0;
	}
};

#endif
