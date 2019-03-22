#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double S0,U,D,R;

   if (GetInputData(S0,U,D,R)==1) return 1;

   //compute risk-neutral probability
   cout << "q = " << RiskNeutProb(U,D,R) << endl;

   //compute stock price at node n=3,i=2
   int n=3; int i=2;
   cout << "n = " << n << endl;
   cout << "i = " << i << endl;
   cout << "S(n,i) = " << S(S0,U,D,n,i) << endl;

   return 0;
}
