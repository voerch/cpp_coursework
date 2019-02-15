#pragma once
#include "date.h"

class Gilt
{

public:
	Gilt(double Coupon, Date MaturityDate) : mCoupon(Coupon), mMaturityDate(MaturityDate) {};
	double CleanPrice(Date SettlementDate, double YieldToMaturity);
	double YieldToMaturity(Date SettlementDate, double CleanPrice);

private:
	const double mCoupon;
	const Date mMaturityDate;
};