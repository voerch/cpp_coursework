#ifndef Exe3_1_Options09_h
#define Exe3_1_Options09_h

#include "BinLattice02.h"
#include "BinModel02.h"

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
      double PriceByCRR(BinModel Model,
         BinLattice<double>& PriceTree,
         BinLattice<double>& XTree,
         BinLattice<double>& YTree);
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
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

class Put: public EurOption, public AmOption
{
   private:
      double K; //strike price

   public:
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

#endif
