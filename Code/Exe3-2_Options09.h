#ifndef Exe3_2_Options09_h
#define Exe3_2_Options09_h

#include "BinLattice02.h"
#include "Exe3-2_BinModel02.h"

class Option
{
   private:
      int N; //steps to expiry

   public:
      void SetN(int N_){N=N_;}
      int GetN(){return N;}
      virtual double Payoff(double z)=0;
};

class EurOption: public virtual Option
{
   public:
      //pricing European option
      double PriceByCRR(BinModel Model);
};

class AmOption: public virtual Option
{
   public:
      //pricing American option
      double PriceBySnell(BinModel Model,
         BinLattice<double>& PriceTree,
         BinLattice<bool>& StoppingTree);
};

class Call: public EurOption, public AmOption
{
   private:
      double K; //strike price

   public:
      Call(int N_, double K_){SetN(N_); K=K_;}
      double Payoff(double z);
};

class Put: public EurOption, public AmOption
{
   private:
      double K; //strike price

   public:
      Put(int N_, double K_){SetN(N_); K=K_;}
      double Payoff(double z);
};

#endif
