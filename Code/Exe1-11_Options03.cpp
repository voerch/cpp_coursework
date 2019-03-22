#include "Exe1-11_Options03.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, int NoOfParams, double Params[])
{
   cout << "Enter steps to expiry N: "; cin >> N;
   for (int n=0; n<NoOfParams; n++)
   {
      cout << "Enter payoff parameter " << n+1
           << " of " << NoOfParams << ": ";
      cin >> Params[n];
   }
   cout << endl;
   return 0;
}

double PriceByCRR(double S0, double U, double D,
   double R, int N, double Params[],
   double (*Payoff)(double z, double Params[]))
{
   double q=RiskNeutProb(U,D,R);
   double Price[N+1];
   for (int i=0; i<=N; i++)
   {
      Price[i]=Payoff(S(S0,U,D,N,i),Params);
   }
   for (int n=N-1; n>=0; n--)
   {
      for (int i=0; i<=n; i++)
      {
         Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+R);
      }
   }
   return Price[0];
}

double CallPayoff(double z, double Params[])
{
   if (z>Params[0]) return z-Params[0];
   return 0.0;
}

double PutPayoff(double z, double Params[])
{
   if (z<Params[0]) return Params[0]-z;
   return 0.0;
}

double DoubDigitPayoff(double z, double Params[])
{
   if (Params[0]<z && z<Params[1]) return 1.0;
   return 0.0;
}
