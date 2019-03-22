#ifndef Exe4_4_Options09_h
#define Exe4_4_Options09_h

#include "BinLattice02.h"
#include "BinModel02.h"

//pricing European option
template<typename Option>
   double PriceByCRR(BinModel Model, Option TheOption)
{
   double q=Model.RiskNeutProb();
   int N=TheOption.GetN();
   vector<double> Price(N+1);
   for (int i=0; i<=N; i++)
   {
      Price[i]=TheOption.Payoff(Model.S(N,i));
   }
   for (int n=N-1; n>=0; n--)
   {
      for (int i=0; i<=n; i++)
      {
         Price[i]=(q*Price[i+1]+(1-q)*Price[i])
            /(1+Model.GetR());
      }
   }
   return Price[0];
}

//pricing American option
template<typename Option>
   double PriceBySnell(BinModel Model,
      BinLattice<double>& PriceTree,
      BinLattice<bool>& StoppingTree,
      Option TheOption)
{
   double q=Model.RiskNeutProb();
   int N=TheOption.GetN();
   PriceTree.SetN(N);
   StoppingTree.SetN(N);
   double ContVal;
   for (int i=0; i<=N; i++)
   {
      PriceTree.SetNode(N,i,TheOption.Payoff(Model.S(N,i)));
      StoppingTree.SetNode(N,i,1);
   }
   for (int n=N-1; n>=0; n--)
   {
      for (int i=0; i<=n; i++)
      {
         ContVal=(q*PriceTree.GetNode(n+1,i+1)
            +(1-q)*PriceTree.GetNode(n+1,i))
            /(1+Model.GetR());
         PriceTree.SetNode(n,i,TheOption.Payoff(Model.S(n,i)));
         StoppingTree.SetNode(n,i,1);
         if (ContVal>PriceTree.GetNode(n,i))
         {
            PriceTree.SetNode(n,i,ContVal);
            StoppingTree.SetNode(n,i,0);
         }
         else if (PriceTree.GetNode(n,i)==0.0)
         {
            StoppingTree.SetNode(n,i,0);
         }
      }
   }
   return PriceTree.GetNode(0,0);
}

class Call
{
   private:
      int N; //steps to expiry
      double K; //strike price

   public:
      int GetN(){return N;}
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

class Put
{
   private:
      int N; //steps to expiry
      double K; //strike price

   public:
      int GetN(){return N;}
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

#endif
