#include <iostream>
#include "Exe5-1_PathDepOption01.h"

using namespace std;

int main()
{
   double S0=100., r=0.03, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double T=1.0/12.0, K=100.0;
   EurCall CallOption(T,K);
   EurPut PutOption(T,K);

   long N=30000;
   cout << "Eur Call Price = "
        << CallOption.PriceByMC(Model,N) << endl;

   cout << "Eur Put Price = "
        << PutOption.PriceByMC(Model,N) << endl;

   return 0;
}

