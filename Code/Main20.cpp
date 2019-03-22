#include <iostream>
#include "PathDepOption02.h"

using namespace std;

int main()
{
   double S0=100., r=0.03, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T=1.0/12.0, K=100.0;
   int m=30;
   ArthmAsianCall Option(T,K,m);

   long N=30000;
   Option.PriceByMC(Model,N);
   cout << "Asian Call Price = " << Option.Price << endl
        << "   Pricing Error = " << Option.PricingError << endl;

   return 0;
}
