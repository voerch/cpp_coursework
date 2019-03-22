#pragma once

class EurOption {

public:
	double T,K;

	double d_plus(double S0, double sigma, double r);
	double d_minus(double S0, double sigma, double r);
	virtual double PriceByJDFormula(double S0, double sigma, double r, double s, double m, double lambda, int Counter)=0;

};


class EurCall : public EurOption {
	public:
		EurCall(double T_, double K_)
		{
			T = T_;  
			K = K_;
		}
		double PriceByBSFormula(double S0, double sigma, double r);
		double PriceByJDFormula(double S0, double sigma, double r, double s, double m, double lambda, int Counter);
};

class Intermediary : public EurCall
{
private:
	double S0, r;

public:
	Intermediary(double T_, double K_, double S0_, double r_) :EurCall(T_, K_)
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