#include <iostream>
#include "Exe5-6_PathDepOption04.h"
#include "Exe5-6_BarrierCall.h"
#include "Exe5-6_EurCall.h"

using namespace std;

int main()
{
   double S0=100.0, r=0.03, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T =1.0/12.0, K=100.0, L=120.0;
   int m=30;

   BarrierCall Option(T,K,L,m);
   EurCall  CVOption(T,K,m);

   long N=30000;
   double epsilon = 0.001;
   Option.PriceByVarRedMC(Model,N,CVOption,epsilon);
   cout << "Barrier call price = " << Option.Price << endl
        << "delta = " << Option.delta << endl
        << "Error = " << Option.PricingError << endl << endl;

   Option.PriceByMC(Model,N,epsilon);
   cout << "Price by direct MC = " << Option.Price << endl
        << "delta    = " << Option.delta << endl
        << "MC Error = " << Option.PricingError << endl;

   return 0;
}

