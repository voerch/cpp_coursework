#include "BinLattice02.h"
#include "BinModel02.h"
#include "Exe4-4_Options09.h"
#include <iostream>
using namespace std;

int main()
{
   BinModel Model;

   if (Model.GetInputData()==1) return 1;

   Put Option;
   Option.GetInputData();
   BinLattice<double> PriceTree;
   BinLattice<bool> StoppingTree;
   PriceBySnell(Model,PriceTree,StoppingTree,Option);
   cout << "American put prices:" << endl << endl;
   PriceTree.Display();
   cout << "American put exercise policy:"
        << endl << endl;
   StoppingTree.Display();
   return 0;
}
