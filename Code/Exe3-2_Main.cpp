#include "Exe3-2_BSModel.h"
#include "Exe3-2_BinModel02.h"
#include "Exe3-2_Options09.h"
#include <iostream>
using namespace std;

int main()
{
   double S0=100.0;
   double r=0.05;
   double sigma=0.2;
   double T=1.0/12.0;
   double K=100.0;
   int N=100;
   cout << "S0 =    " << S0 << endl;
   cout << "r  =    " << r << endl;
   cout << "sigma = " << sigma << endl;
   cout << "T =     " << T << endl;
   cout << "K =     " << K << endl;
   cout << "N =     " << N << endl;
   cout << endl;

   BSModel Model(S0,r,sigma);
   double h=T/N;
   BinModel ApproxModel=Model.ApproxBinModel(h);

   Put Option(N,K);
   BinLattice<double> PriceTree;
   BinLattice<bool> StoppingTree;
   Option.PriceBySnell(ApproxModel,PriceTree,StoppingTree);
   cout << "American put option price = "
        << PriceTree.GetNode(0,0)
        << endl << endl;

   return 0;
}
