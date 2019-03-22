#include "BinLattice02.h"
#include "BinModel02.h"
#include "Exe3-1_Options09.h"
#include <iostream>
using namespace std;

int main()
{
   BinModel Model;

   if (Model.GetInputData()==1) return 1;

   Put Option;
   Option.GetInputData();
   BinLattice<double> PriceTree;
   BinLattice<double> XTree;
   BinLattice<double> YTree;
   Option.PriceByCRR(Model,PriceTree,XTree,YTree);
   cout << "European put prices:"
        << endl << endl;
   PriceTree.Display();
   cout << "Stock positions in replicating strategy:"
        << endl << endl;
   XTree.Display();
   cout << "Money market account positions in replicating strategy:"
        << endl << endl;
   YTree.Display();

   return 0;
}
