#pragma once
#include "JDModel.h"

class EurOption {

protected:
	double T,K;
	
	EurOption(double T_, double K_) :T(T_), K(K_) {};
	double d_plus(double S0, double sigma, double r);
	double d_minus(double S0, double sigma, double r);

public:
	virtual ~EurOption() {};
	double PriceByJDMC(JDModel Model, int samplingDates, int nPaths);
	virtual double Payoff(double S) = 0;
	virtual double PriceByBSFormula(double S0, double sigma, double r) = 0;
	virtual double PriceByJDFormula(double S0, double sigma, double r, double s, double m, double lambda, int Counter) = 0;
	double PricingError;
};


class EurCall : public EurOption {
	public:
		~EurCall() {};
		EurCall(double T_, double K_) : EurOption(T_, K_) {};
		double Payoff(double S);
		double PriceByBSFormula(double S0, double sigma, double r);
		double PriceByJDFormula(double S0, double sigma, double r, double s, double m, double lambda, int Counter);
};

class Intermediary : public EurCall
{
	double S0, r;

public:
	~Intermediary() {};
	Intermediary(double T_, double K_, double S0_, double r_) :EurCall(T_, K_), S0(S0_), r(r_) { };

	double Value(double sigma)
	{
		return PriceByBSFormula(S0, sigma, r);
	}
	double Deriv(double sigma)
	{
		return 0;
	}
};

