#ifndef Options05_h
#define Options05_h

#include "BinModel02.h"

class EurOption
{
   private:
      //steps to expiry
      int N;
      //pointer to payoff function
      double (*Payoff)(double z, double K);
   public:
      void SetN(int N_){N=N_;}
      void SetPayoff
         (double (*Payoff_)(double z, double K))
         {Payoff=Payoff_;}
      //pricing European option
      double PriceByCRR(BinModel Model, double K);
};

//computing call payoff
double CallPayoff(double z, double K);

class Call: public EurOption
{
   private:
      double K; //strike price
   public:
      Call(){SetPayoff(CallPayoff);}
      double GetK(){return K;}
      int GetInputData();
};

//computing put payoff
double PutPayoff(double z, double K);

class Put: public EurOption
{
   private:
      double K; //strike price
   public:
      Put(){SetPayoff(PutPayoff);}
      double GetK(){return K;}
      int GetInputData();
};

#endif
