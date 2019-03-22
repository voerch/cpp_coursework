#include "Solver03.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Bond
{
   private:
      double F; //face value
      double T; //maturity time
      vector<double> C; //coupons
      vector<double> t; //coupon times
   public:
      Bond(double F_, double T_, vector<double>& C_, vector<double>& t_)
         {F=F_; T=T_; C=C_; t=t_;}
      double Value(double y)
      {
         double P=0;
         for (unsigned int n=0; n<C.size(); n++)
            P+=C[n]*exp(-y*t[n]);
         P+=F*exp(-y*T);
         return P;
      }
      double Deriv(double y)
      {
         double D=0;
         for (unsigned int n=0; n<C.size(); n++)
            D+=-C[n]*t[n]*exp(-y*t[n]);
         D+=-F*T*exp(-y*T);
         return D;
      }
};

int main()
{
   double F=100.0; //face value
   double T=3.0; //maturity time
   vector<double> C; //coupons
   C.push_back(1.2); C.push_back(1.2); C.push_back(1.2);
   vector<double> t; //coupon times
   t.push_back(1.0); t.push_back(2.0); t.push_back(3.0);

   Bond MyBond(F,T,C,t);

   double P=98.56;
   double Acc=0.0001;
   double y;

   cout << "F = " << F << endl;
   cout << "T = " << F << endl;
   cout << "coupons: " << endl;
   for (unsigned int n=0; n<C.size(); n++)
   cout << "C" << n << " = " << C[n] << " " <<endl;
   cout << "tenors: " << endl;
   for (unsigned int n=0; n<t.size(); n++)
   cout << "T" << n << " = " << t[n] << " " <<endl;
   cout << "P = " << P << endl << endl;

   double LEnd=0.0;
   double REnd=1.0;
   y=SolveByBisect(&MyBond,P,LEnd,REnd,Acc);
   cout << "Yield by bisection method: " << y << endl;

   double Guess=0.2;
   y=SolveByNR(&MyBond,P,Guess,Acc);
   cout << "Yield by Newton-Raphson method: " << y << endl;

   return 0;
}
