#include "BinModel02.h"
#include "Options07.h"
#include <iostream>
using namespace std;

int main()
{
   BinModel Model;

   if (Model.GetInputData()==1) return 1;

   Call Option1;
   Option1.GetInputData();
   cout << "European call option price = "
        << Option1.PriceByCRR(Model)
        << endl;
   cout << "American call option price = "
        << Option1.PriceBySnell(Model)
        << endl << endl;

   Put Option2;
   Option2.GetInputData();
   cout << "European put option price = "
        << Option2.PriceByCRR(Model)
        << endl;
   cout << "American put option price = "
        << Option2.PriceBySnell(Model)
        << endl << endl;

   return 0;
}
