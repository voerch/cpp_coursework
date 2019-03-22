#include "Solver03.h"
#include <iostream>
using namespace std;

class F1
{
   public:
      double Value(double x){return x*x-2;}
      double Deriv(double x){return 2*x;}
} MyF1;

class F2
{
   private:
      double a; //parameter
   public:
      F2(double a_){a=a_;}
      double Value(double x){return x*x-a;}
      double Deriv(double x){return 2*x;}
} MyF2(3.0);

int main()
{
   double Acc=0.001;
   double LEnd=0.0, REnd=2.0;
   double Tgt=0.0;
   cout << "Root of F1 by bisect: "
        << SolveByBisect(&MyF1,Tgt,LEnd,REnd,Acc)
        << endl;
   cout << "Root of F2 by bisect: "
        << SolveByBisect(&MyF2,Tgt,LEnd,REnd,Acc)
        << endl;
   double Guess=1.0;
   cout << "Root of F1 by Newton-Raphson: "
        << SolveByNR(&MyF1,Tgt,Guess,Acc)
        << endl;
   cout << "Root of F2 by Newton-Raphson: "
        << SolveByNR(&MyF2,Tgt,Guess,Acc)
        << endl;
   return 0;
}
