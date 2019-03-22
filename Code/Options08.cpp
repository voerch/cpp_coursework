#include "Options08.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double EurOption::PriceByCRR(BinModel Model)
{
   double q=Model.RiskNeutProb();
   int N=GetN();
   vector<double> Price(N+1);
   for (int i=0; i<=N; i++)
   {
      Price[i]=Payoff(Model.S(N,i));
   }
   for (int n=N-1; n>=0; n--)
   {
      for (int i=0; i<=n; i++)
      {
         Price[i]=(q*Price[i+1]+(1-q)*Price[i])
            /(1+Model.GetR());
      }
   }
   return Price[0];
}

double AmOption::PriceBySnell(BinModel Model)
{
   double q=Model.RiskNeutProb();
   int N=GetN();
   vector<double> Price(N+1);
   double ContVal;
   for (int i=0; i<=N; i++)
   {
      Price[i]=Payoff(Model.S(N,i));
   }
   for (int n=N-1; n>=0; n--)
   {
      for (int i=0; i<=n; i++)
      {
         ContVal=(q*Price[i+1]+(1-q)*Price[i])
                              /(1+Model.GetR());
         Price[i]=Payoff(Model.S(n,i));
         if (ContVal>Price[i]) Price[i]=ContVal;
      }
   }
   return Price[0];
}

int Call::GetInputData()
{
   cout << "Enter call option data:" << endl;
   int N;
   cout << "Enter steps to expiry N: "; cin >> N;
   SetN(N);
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double Call::Payoff(double z)
{
   if (z>K) return z-K;
   return 0.0;
}

int Put::GetInputData()
{
   cout << "Enter put option data:" << endl;
   int N;
   cout << "Enter steps to expiry N: "; cin >> N;
   SetN(N);
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double Put::Payoff(double z)
{
   if (z<K) return K-z;
   return 0.0;
}
