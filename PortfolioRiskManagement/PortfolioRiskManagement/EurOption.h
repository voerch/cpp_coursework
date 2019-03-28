#pragma once

class EurOption
{
protected:
	double Strike, TimeToExpiry;
	double dPlus(double S0, double sigma, double r);
	double dMinus(double S0, double sigma, double r);

public:
	virtual ~EurOption() {};
	EurOption(double Strike_, double TimeToExpiry_) :Strike(Strike_), TimeToExpiry(TimeToExpiry_) {};

	virtual double PriceByBS(double S0, double r, double sigma) = 0;
	virtual double PriceDelta(double S0, double r, double sigma) = 0;
	virtual double PriceGamma(double S0, double r, double sigma) = 0;
	virtual double PriceTheta(double S0, double r, double sigma) = 0;

};

class Call : public EurOption
{

public:

	virtual ~Call() {};
	Call(double Strike_, double TimeToExpiry_) : EurOption(Strike_, TimeToExpiry_) {};

	double PriceByBS(double S0, double r, double sigma);
	double PriceDelta(double S0, double r, double sigma);
	double PriceGamma(double S0, double r, double sigma);
	double PriceTheta(double S0, double r, double sigma);


};