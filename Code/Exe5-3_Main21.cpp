#include <iostream>
#include "Exe5-3_PathDepOption03.h"

using namespace std;

int main()
{
   double S0=100., r=0.03, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T=0.5, K=100.0;
   int m = 30;

   long N=30000;
   double epsilon=0.001;
   ArthmAsianCall Option1(T,K,m);
   Option1.PriceByMC(Model,N,epsilon) ;
   cout << "Arithmetic Call:" << endl;
   cout << " Option Price = " << Option1.Price << endl
        << "Pricing Error = " << Option1.PricingError << endl
        << "        delta = " << Option1.delta << endl
        << "          rho = " << Option1.rho << endl
        << "         vega = " << Option1.vega << endl
        << "        theta = " << Option1.theta << endl
        << "        gamma = " << Option1.gamma << endl;

   EurCall Option2(T,K);
   cout << "European Call:" << endl;
   Option2.PriceByMC(Model,N,epsilon);
   cout << " Option Price = " << Option2.Price << endl
        << "Pricing Error = " << Option2.PricingError << endl
        << "        delta = " << Option2.delta << endl
        << "          rho = " << Option2.rho << endl
        << "         vega = " << Option2.vega << endl
        << "        theta = " << Option2.theta << endl
        << "        gamma = " << Option2.gamma << endl;


   return 0;
}
