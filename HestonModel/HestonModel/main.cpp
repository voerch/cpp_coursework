#include <iostream>
#include "EurOption.h"

using namespace std;

int main()
{
   double S0=100.0, r=0.05, sigma0Sq=0.04, sigmaSq = 0.09, timestep = 1.0/365.0, a = 1.25, eta = 0.3, rho = 0.1;
   HestonModel Model(S0, r, sigma0Sq, sigmaSq, timestep, a, eta, rho);

   double T=1, K=105;
   int m=365;

   CallOption Opt(T, K, m);

   long N=10000;
   double epsilon = 0.001;

   Opt.PriceByMC(Model, N, epsilon);
   system("pause");
   return 0;
}
