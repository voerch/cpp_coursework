#include "EurOption.h"
#include <iostream>

using namespace std;

int main()
{
	double Strike, Volatility, Rate, TimeToExpiry, SharePrice, PutCallFlag;

	Strike = 102; TimeToExpiry = 0.75; SharePrice = 100; 
	Volatility = 0.25; Rate = 0.06;

	cout << "Call(1) or Put(-1)?";
	cin >> PutCallFlag;

	
	if (PutCallFlag == 1) 
	{
		EurCall TestCall(TimeToExpiry, Strike);
		cout << TestCall;
	}

	else if (PutCallFlag == -1)
	{
		EurPut TestPut(TimeToExpiry, Strike);
		cout << TestPut;
	}
	else
	{
		cout << "WRONG INPUT" << endl;
	}

	system("pause");
	return 0;
}