#include <iostream>
#include "PathDepOption01.h"

using namespace std;

int main()
{
   double S0=105.0, r=0.05, sigma=0.25;
   BSModel Model(S0,r,sigma);

   double T=1, K_min=100.0, K_max=110, Principal = 1000000.0;
   int m=252;
   AccrualNote Opt(T, K_min, K_max, m, Principal);

   long N=100000;
   double epsilon = 0.001;

   Opt.PriceByMC(Model, N, epsilon);
   system("pause");
   return 0;
}
