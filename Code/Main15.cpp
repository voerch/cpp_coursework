#include "Solver01.h"
#include <iostream>
using namespace std;

double F1(double x){return x*x-2;}
double DF1(double x){return 2*x;}

int main()
{
   double Acc=0.001;
   double LEnd=0.0, REnd=2.0;
   double Tgt=0.0;
   cout << "Root of F1 by bisect: "
        << SolveByBisect(F1,Tgt,LEnd,REnd,Acc)
        << endl;
   double Guess=1.0;
   cout << "Root of F1 by Newton-Raphson: "
        << SolveByNR(F1,DF1,Tgt,Guess,Acc)
        << endl;
   return 0;
}
