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

double NewtonSymb(int N, int n)
{
   if (n<0 || n>N) return 0;
   double result=1;
   for (int i=1; i<=n; i++) result=result*(N-n+i)/i;
   return result;
}

double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K)
{
   double p=RiskNeutProb(U,D,R);
   double Price=0;
   for (int n=0; n<=N; n++)
   {
      Price=Price
            +NewtonSymb(N,n)*pow(p,n)*pow(1-p,N-n)
            *CallPayoff(S(S0,U,D,N,n),K)/pow(1+R,N);
   }
   return Price;
}

double CallPayoff(double z, double K)
{
   if (z>K) return z-K;
   return 0.0;
}
