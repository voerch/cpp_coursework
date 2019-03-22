#include "BinModel02.h"
#include "Options04.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   BinModel Model;

   if (Model.GetInputData()==1) return 1;

   double K;   //strike price
   int N;      //steps to expiry

   cout << "Enter call option data:" << endl;
   GetInputData(N,K);
   cout << "European call option price = "
        << PriceByCRR(Model,N,K,CallPayoff)
        << endl << endl;

   cout << "Enter put option data:" << endl;
   GetInputData(N,K);
   cout << "European put option price =  "
        << PriceByCRR(Model,N,K,PutPayoff)
        << endl << endl;

   return 0;
}
