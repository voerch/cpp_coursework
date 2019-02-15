#include "Gilt.h"
#include <iostream>
#include "Solver02.h"
using namespace std;

int main()
{
	Date MaturityDate(7, 9, 2039);
	Date SettlementDate(12, 12, 2013);
	double Coupon = 0.0425;
	double CleanPrice = 111.95;

	Gilt Test(Coupon, MaturityDate);
		
	cout << Test.CleanPrice(SettlementDate, 0.03539);




	system("pause");
	return 0;
}

