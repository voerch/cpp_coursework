#include <iostream>
#include "EurOption.h"
#include "Solver03.h"
#include <fstream>
using namespace std;

int main()
{
	double S0 = 100.0, r = 0.05, sigma = 0.15;
	double lambda = 1.0, m = 0.05, s = 0.3;
	double K = 105.0, T = 0.5;
	int Counter = 10000;
	EurCall Option(T, K);
	double Price = Option.PriceByJDFormula(S0, sigma, r, s, m, lambda, Counter);
	cout << "Price: " << Price << endl;
	
	
	Intermediary func(T, K, S0, r);

	double Acc = 0.0001;
	double LEnd = 0.01, REnd = 1.0;
	double Tgt = Price;
	double ImpliedVol = SolveByBisect(&func, Tgt, LEnd, REnd, Acc) * 100;
	std::cout << "Implied volatility:  " << ImpliedVol << endl;
	double impVol[90];

	for (K = 60; K <= 150; K++) {

		EurCall NewOption(T, K);
		Tgt = NewOption.PriceByJDFormula(S0, sigma, r, s, m, lambda, Counter);

		Intermediary func(T, K, S0, r);
		impVol[int(K) - 60] = SolveByBisect(&func, Tgt, LEnd, REnd, Acc) * 100;
	}

	ofstream myfile("impvol.csv");
	if (myfile.is_open())
	{
		for (int count = 0; count <= 90; count++) {
			myfile << count + 60 << "," << impVol[count] << endl;
		}
		myfile.close();
	}
	
	system("pause");
	return 0;
}