#include "NormalCDF.h"
#include <math.h>
#include <iostream>

using namespace std;

int main() {

	double SharePrice, InterestRate, DivYield, Vol, NumberOfShares, Strike, Expiry;

	cout << "Please input market data:" << endl;
	cout << "\tShare price:";
	cin >> SharePrice;
	cout << "\tInterest Rate:";
	cin >> InterestRate;
	cout << "\tDividend Yield:";
	cin >> DivYield;
	cout << "\tVolatility:";
	cin >> Vol;

	cout << "Please input trade data:" << endl;
	cout << "\t Number of shares:";
	cin >> NumberOfShares;
	cout << "\tStrike Price:";
	cin >> Strike;
	cout << "\tTime to expiry in years:";
	cin >> Expiry;

	double Forward, DiscountFactor, VolTimesSqrtT, OptionPrice,d1,d2;
	
	Forward = SharePrice * exp(Expiry*(InterestRate - DivYield));
	DiscountFactor = exp(-Expiry * InterestRate);
	VolTimesSqrtT = Vol * sqrt(Expiry);
	
	d1 = (log(Forward / Strike) / VolTimesSqrtT) + (0.5*VolTimesSqrtT);
	d2 = (log(Forward / Strike) / VolTimesSqrtT) - (0.5*VolTimesSqrtT);

	OptionPrice = DiscountFactor*((Forward*CumulativeNormalDistribution(d1)) - (Strike * CumulativeNormalDistribution(d2))) * NumberOfShares;

	cout << OptionPrice << endl;
	system("pause");
	return 0;

}