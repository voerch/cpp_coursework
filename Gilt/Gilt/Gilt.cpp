#include "Gilt.h"
#include "Solver02.h"
#include <cmath>

double Gilt::CleanPrice(Date SettlementDate, double YieldToMaturity)
{
	Date PreviousCoupon = mMaturityDate;
	Date NextCoupon = mMaturityDate;
	PreviousCoupon.addMonths(-6);
	double r = double(SettlementDate.daysDiff(PreviousCoupon));
	double s = double(PreviousCoupon.daysDiff(NextCoupon));
	int m = SettlementDate.daysDiff(NextCoupon);
	int n = 0;

	while (r < 0 && m < 180)
	{
		PreviousCoupon.addMonths(-6);
		NextCoupon.addMonths(-6);
		r = double(SettlementDate.daysDiff(PreviousCoupon));
		m = double(SettlementDate.daysDiff(NextCoupon));
		n += 1;
	}

	m = abs(m);
	double A = r / s * mCoupon / 2;
	double Price = 0;
	
	for (int i = 1; i <= n; i++) 
	{
		Price += ((mCoupon / 2) / pow(1 + (YieldToMaturity / 2) , i)) + (100 / pow(1 + (YieldToMaturity / 2), n));
	}
	
	double CleanPrice = (Price * (1 / pow(1 + (YieldToMaturity / 2), m / s))) - A;
	
	return CleanPrice;

}


class F1 : public Function
{
private:
	Gilt G;
	Date SettlementDate;

public:
	F1(double Coupon, Date MaturityDate, Date fSettlementDate) :G(Coupon, MaturityDate),SettlementDate(fSettlementDate) {};

	double Value(double YtM)
	{
		return (G.CleanPrice(SettlementDate, YtM));
	}

};

double Gilt::YieldToMaturity(Date SettlementDate, double CleanPrice)
{
	double Accuracy = 0.0001;	double Target = 0.5;
	double LEnd = 0;			double REnd = 1;

	Function MyF1(mCoupon, mMaturityDate, SettlementDate);

	return SolveByBisect(&MyF1, Target, LEnd, REnd, Accuracy);

}