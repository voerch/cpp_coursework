#pragma once


class UpAndOutEurCall
{
	public:
		UpAndOutEurCall(double T_, double K_) { T = T_; K = K_; }
		double PriceByBSFormula(double S0, double B, double sigma, double r);
		double PriceByCRR(double N, double S0, double B, double sigma, double r);
	protected:
		double T,K;
		double D(double x, double r, double sigma, double T);
};
