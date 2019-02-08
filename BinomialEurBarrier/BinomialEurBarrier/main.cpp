#include "UpAndOutEurCall.h"
#include <iostream>

using namespace std;
int main()
{
	UpAndOutEurCall Testing(1,100);

	for (int i = 50; i <= 500; i += 50)
	{
		cout << "N = " << i << endl;
		cout << "CRR =" << Testing.PriceByCRR(i, 98, 130, 0.2, 0.05) << endl;
	}

	cout << "Analytical Result = " << Testing.PriceByBSFormula(98, 130, 0.2, 0.05) << endl;

	system("pause");
	return(0);

}