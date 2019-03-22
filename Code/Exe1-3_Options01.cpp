#include "Options01.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K)
{
   cout << "Enter steps to expiry N: "; cin >> N;
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K)
{
   double q=RiskNeutProb(U,D,R);
   double Price[N+1];
   int i=0;
   while (i<=N)
   {
      Price[i]=CallPayoff(S(S0,U,D,N,i),K);
      i++;
   }
   int n=N-1;
   while (n>=0)
   {
      int i=0;
      while (i<=n)
      {
         Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+R);
         i++;
      }
      n--;
   }
   return Price[0];
}

double CallPayoff(double z, double K)
{
   if (z>K) return z-K;
   return 0.0;
}
