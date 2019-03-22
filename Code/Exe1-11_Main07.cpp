#include "BinModel01.h"
#include "Exe1-11_Options03.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double S0,U,D,R;

   if (GetInputData(S0,U,D,R)==1) return 1;

   int N;               //steps to expiry

   cout << "Enter call option data:" << endl;
   double CallParams[1];
   GetInputData(N,1,CallParams);
   cout << "European call option price = "
        << PriceByCRR(S0,U,D,R,N,CallParams,CallPayoff)
        << endl << endl;

   cout << "Enter put option data:" << endl;
   double PutParams[1];
   GetInputData(N,1,PutParams);
   cout << "European put option price =  "
        << PriceByCRR(S0,U,D,R,N,PutParams,PutPayoff)
        << endl << endl;

   cout << "Enter double-digital option data:" << endl;
   double DoubDigitParams[2];
   GetInputData(N,2,DoubDigitParams);
   cout << "European double-digital option price =  "
        << PriceByCRR(S0,U,D,R,N,DoubDigitParams,DoubDigitPayoff)
        << endl << endl;

   return 0;
}
