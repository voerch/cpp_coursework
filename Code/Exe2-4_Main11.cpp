#include "BinModel02.h"
#include "Options06.h"
#include "DoubDigitOpt.h"
#include "Exe2-4_SpreadOptions.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   BinModel Model;

   if (Model.GetInputData()==1) return 1;

   Call Option1;
   Option1.GetInputData();
   cout << "European call option price = "
        << Option1.PriceByCRR(Model)
        << endl << endl;

   Put Option2;
   Option2.GetInputData();
   cout << "European put option price = "
        << Option2.PriceByCRR(Model)
        << endl << endl;

   DoubDigitOpt Option3;
   Option3.GetInputData();
   cout << "European double-digital option price = "
        << Option3.PriceByCRR(Model)
        << endl << endl;

   StrangleOpt Option4;
   Option4.GetInputData();
   cout << "European strangle spread option price = "
        << Option4.PriceByCRR(Model)
        << endl << endl;

   ButterflyOpt Option5;
   Option5.GetInputData();
   cout << "European butterfly spread option price = "
        << Option5.PriceByCRR(Model)
        << endl << endl;

   return 0;
}
