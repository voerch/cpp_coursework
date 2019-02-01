#pragma once
#include <iostream>
using namespace std;

class EurOption
{
	public:
		EurOption(double T_, double K_) { T = T_; K = K_; }
		virtual double PriceByBSFormula(double S0, double sigma, double r) = 0;
		virtual double DeltaByBSFormula(double S0, double sigma, double r) = 0;
		virtual double GammaByBSFormula(double S0, double sigma, double r) = 0;
		virtual double ThetaByBSFormula(double S0, double sigma, double r) = 0;

	protected:
		double T, K;
		double d_plus(double S0, double sigma, double r);
		double d_minus(double S0, double sigma, double r);
};

class EurCall : public EurOption
{
	public:
		EurCall(double T_, double K_) : EurOption(T_,K_) {};
		double PriceByBSFormula(double S0, double sigma, double r);
		double DeltaByBSFormula(double S0, double sigma, double r);
		double GammaByBSFormula(double S0, double sigma, double r);
		double ThetaByBSFormula(double S0, double sigma, double r);
		friend ostream& operator<<(ostream& stream, EurCall &Call);
};

class EurPut : public EurOption
{
	public:
		EurPut(double T_, double K_) : EurOption(T_, K_) {};
		double PriceByBSFormula(double S0, double sigma, double r);
		double DeltaByBSFormula(double S0, double sigma, double r);
		double GammaByBSFormula(double S0, double sigma, double r);
		double ThetaByBSFormula(double S0, double sigma, double r);
		friend ostream& operator<<(ostream& stream, EurPut &Put);
};

struct Calculations
{

};