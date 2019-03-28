#include <iostream>
#include "EurOption.h"
#include "Solver03.h"
#include <fstream>
#include <vector>
#include "JDModel.h"

#include <iomanip>
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

	double PriceAnalytic = OptionPtr->PriceByJDFormula(S0, sigma, r, s, m, lambda, Counter);

	cout << fixed << setprecision(2);

	cout << setw(10) << "A Price" << setw(10) << "MC Price" << setw(10) << "MC Error" << endl;
	cout << "===============================" << endl ;

	JDModel Model(S0, sigma, r, s, m, lambda);
	int samplingDates = 52;
	int nPaths = 7600;
	double PriceMC = OptionPtr->PriceByJDMC(Model, samplingDates, nPaths);
	
	cout << setw(10) << PriceAnalytic  << setw(10) << PriceMC << setw(10) << OptionPtr->PricingError << endl;

	delete OptionPtr;

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
	

	//cout << fixed << setprecision(2) << setw(10) << left;

	//cout << endl << endl;
	//cout << "Option"
	//	 << "Price"
	//	 << "Delta"
	//	 << "Gamma"
	//	 << "Theta" << endl;
	//cout << "==================================================" << endl;


	//cout <<  5
	//	<<  100.565656595
	//	<<  10
	//	<<  2100
	//	<<  50 << endl;

	system("pause");
	return 0;
}