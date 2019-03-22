#include "Solver03.h"
#include "EurCall.h"
#include <iostream>
using namespace std;

class Intermediary: public EurCall
{
   private:
      double S0,r;
   public:
      Intermediary(double S0_, double r_, double T_, double K_)
         : EurCall(T_,K_) {S0=S0_; r=r_;}
      double Value(double sigma)
      {
         return PriceByBSFormula(S0,sigma,r);
      }
      double Deriv(double sigma)
      {
         return VegaByBSFormula(S0,sigma,r);
      }
};

int main()
{
   double S0=100.0;
   double r=0.1;
   double T=1.0;
   double K=100.0;
   Intermediary Call(S0,r,T,K);

   double Acc=0.001;
   double LEnd=0.01, REnd=1.0;
   double Tgt=12.56;
   cout << "Implied vol by bisect: "
        << SolveByBisect(&Call,Tgt,LEnd,REnd,Acc)
        << endl;
   double Guess=0.23;
   cout << "Implied vol by Newton-Raphson: "
        << SolveByNR(&Call,Tgt,Guess,Acc)
        << endl;
   return 0;
}
