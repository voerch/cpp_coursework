#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   double S0,U,D,R;

   //entering data
   cout << "Enter S0: "; cin >> S0;
   cout << "Enter U:  "; cin >> U;
   cout << "Enter D:  "; cin >> D;
   cout << "Enter R:  "; cin >> R;
   cout << endl;

   //making sure that 0<S0, -1<D<U, -1<R
   if (S0<=0.0 || U<=-1.0 || D<=-1.0 || U<=D
                                     || R<=-1.0)
   {
      cout << "Illegal data ranges" << endl;
      cout << "Terminating program" << endl;
      return 1;
   }

   //checking for arbitrage
   if (R>=U || R<=D)
   {
      cout << "Arbitrage exists" << endl;
      cout << "Terminating program" << endl;
      return 1;
   }

   cout << "Input data checked" << endl;
   cout << "There is no arbitrage" << endl << endl;

   //compute risk-neutral probability
   cout << "q = " << (R-D)/(U-D) << endl;

   int n,i;
   cout << "Enter n: "; cin >> n;
   cout << "Enter i: "; cin >> i;
   cout << "n = " << n << endl;
   cout << "i = " << i << endl;
   //compute stock price at node n,i
   cout << "S(n,i) = " << S0*pow(1+U,i)*pow(1+D,n-i)
                       << endl;

   return 0;
}
