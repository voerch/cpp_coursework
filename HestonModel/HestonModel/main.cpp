#include <iostream>
#include "EurOption.h"
#include "Solver03.h"
#include <fstream>
#include <iomanip>
using namespace std;



int main()
{
   double S0=100.0, r=0.05, sigma0Sq=0.04, sigmaSq = 0.09, timestep = 1.0/365.0, a = 1.25, eta = 0.3, rho = 0.1;
   HestonModel Model(S0, r, sigma0Sq, sigmaSq, timestep, a, eta, rho);

   double T=1.0, K=105.0;
   int m=365;

   CallOption Opt(T, K, m);

   long N=1000000;
   double epsilon = 0.001;
   Opt.PriceByMC(Model, N, epsilon);
   cout << "Price: " << Opt.Price << " +/- " << Opt.PriceError << endl;
   
   Intermediary func(T, K, m, S0, r);

   double Acc = 0.0001;
   double LEnd = 0.01, REnd = 1.0;
   double Tgt = Opt.Price;
   double ImpliedVol = SolveByBisect(&func, Tgt, LEnd, REnd, Acc) * 100;
   double TgtLow = Opt.Price - Opt.PriceError;
   cout << fixed << setprecision(10);
   double ImpliedVolError = ImpliedVol - (SolveByBisect(&func, TgtLow, LEnd, REnd, Acc) * 100);
   std::cout << "Implied volatility:  " << ImpliedVol << " +/- " << ImpliedVolError <<endl;


   double impVol[90];
   SamplePath S(m);
   SamplePath Vol(m);
   Model.GenerateSamplePath(T, m, S, Vol);
   for (K = 60; K <= 150; K++) {

	   CallOption NewOpt(T, K, m);
	   Tgt = NewOpt.VolatilitySmile(Model, N, epsilon, S);

	   Intermediary func(T, K, m, S0, r);
	   impVol[int(K)-60] = SolveByBisect(&func, Tgt, LEnd, REnd, Acc) * 100;
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
