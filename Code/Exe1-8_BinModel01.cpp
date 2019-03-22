#include <iostream>
#include <cmath>
using namespace std;

double RiskNeutProb(double U, double D, double R)
{
   return (R-D)/(U-D);
}

double S(double S0, double U, double D, int n, int i)
{
   return S0*pow(1+U,i)*pow(1+D,n-i);
}

int GetInputData(double* pS0,
                 double* pU, double* pD, double* pR)
{
   //entering data
   cout << "Enter S0: "; cin >> *pS0;
   cout << "Enter U:  "; cin >> *pU;
   cout << "Enter D:  "; cin >> *pD;
   cout << "Enter R:  "; cin >> *pR;
   cout << endl;

   //making sure that 0<S0, -1<D<U, -1<R
   if (*pS0<=0.0 || *pU<=-1.0 || *pD<=-1.0 || *pU<=*pD
                                           || *pR<=-1.0)
   {
      cout << "Illegal data ranges" << endl;
      cout << "Terminating program" << endl;
      return 1;
   }

  //checking for arbitrage
   if (*pR>=*pU || *pR<=*pD)
   {
      cout << "Arbitrage exists" << endl;
      cout << "Terminating program" << endl;
      return 1;
   }

   cout << "Input data checked" << endl;
   cout << "There is no arbitrage" << endl << endl;

   return 0;
}
