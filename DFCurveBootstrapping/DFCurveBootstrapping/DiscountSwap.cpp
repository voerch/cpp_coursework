#include "DiscountSwap.h"

/*
price 0 al tersten coz
wrap swap object
solver02.h
*/
void DiscountCurve::insert(double T, double Dt)
{
	Curve.insert(T, Dt);
}

double DiscountCurve::getDF(double T)
{
	return Curve.value(T);
}

double Swap::price(DiscountCurve& dc) 
{
	double Sum, t_i;
	int i;
	double FutureCashFlows = mMaturity * mFrequency;

	for(i = 1;i <= FutureCashFlows;i++)
	{
		t_i = i / mFrequency;
		Sum += dc.getDF(t_i);
	}

	double price = (mRate / mFrequency) * Sum + dc.getDF(t_i) - 1;
	return price;
}

double Swap::parRate(const DiscountCurve& dc) 
{

}

double Bootstraper::Bootsrap() 
{
	for (int i = 0; i <= n; i++)
	{

	}
}