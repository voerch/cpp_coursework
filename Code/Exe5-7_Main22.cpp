#include <iostream>
#include "PathDepOption04.h"
#include "Exe5-7_ContGmtrAsianCall.h"

using namespace std;

int main()
{
   double S0=100.0, r=0.03, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T =1.0/12.0, K=100.0;

   // For the considered integrals to be computed with sufficient
   // accuracy, we have to choose a large m
   int m=300;

   ArthmAsianCall Option(T,K,m);
   ContGmtrAsianCall  CVOption(T,K,m);

   long N=30000;
   Option.PriceByVarRedMC(Model,N,CVOption);
   cout << "Arithmetic call price = " << Option.Price << endl
        << "Error = " << Option.PricingError << endl;

   CVOption.PriceByMC(Model,N);
   cout << "Price by direct MC = " << CVOption.Price << endl
        << "MC Error = " << CVOption.PricingError << endl;

   return 0;
}
