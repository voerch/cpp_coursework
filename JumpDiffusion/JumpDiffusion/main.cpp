#include <iostream>
#include "EurOption.h"
#include "Solver03.h"
#include <fstream>
#include <vector>
#include "JDModel.h"
using namespace std;

double impliedVol(Intermediary func, double Tgt)
{
	double Acc = 0.0001, LEnd = 0.01, REnd = 1.0;

	return SolveByBisect(&func, Tgt, LEnd, REnd, Acc);
}

int main()
{
	double S0 = 100.0, r = 0.05, sigma = 0.15;
	double lambda = 1.0, m = 0.05, s = 0.3;
	double K = 105.0, T = 0.5;
	int Counter = 10000;

	EurOption* OptionPtr;
	OptionPtr = new EurCall(T, K);

	double Price = OptionPtr->PriceByJDFormula(S0, sigma, r, s, m, lambda, Counter);
	cout << "Analytic Price: " << Price << endl;
	
	JDModel Model(S0, sigma, r, s, m, lambda);
	int samplingDates = 52;
	int nPaths = 76000;
	Price = OptionPtr->PriceByJDMC(Model, samplingDates, nPaths);


	//Intermediary func(T, K, S0, r);
	//std::cout << "Implied volatility:  " << impliedVol(func, Price) << endl;

	//vector<double> impVol;
	//vector<double> impVolSigma;

	//for (K = 60; K <= 150; K++) {

	//	OptionPtr = new EurCall(T, K);
	//	Price = OptionPtr->PriceByJDFormula(S0, sigma, r, s, m, lambda, Counter);
	//	Intermediary func(T, K, S0, r);
	//	impVol.push_back(impliedVol(func, Price));
	//}

	//ofstream myfile("impvol.csv");
	//if (myfile.is_open())
	//{
	//	for (unsigned int count = 0; count < impVol.size(); count++) {
	//		myfile << count + 60 << ";" << impVol[count] << endl;
	//	}
	//	myfile.close();
	//}
	
	system("pause");
	return 0;
}