#pragma once
#include "interpolator.h"

class DiscountCurve
{
	public:
		DiscountCurve() {Curve.insert(0,1);}
		void insert(double T, double Dt);
		double getDF(double T);	
	private:
		LinearInterpolator Curve;

};

class Swap
{
	Swap(double Maturity, double Rate, double Frequency) :mMaturity(Maturity), mRate(Rate), mFrequency(Frequency) {};
	double price(DiscountCurve& dc);
	double parRate(const DiscountCurve& dc);
	private:
		double mMaturity, mRate, mFrequency;

};

class Bootstraper
{
	DiscountCurve dc;
	double Bootsrap();



};