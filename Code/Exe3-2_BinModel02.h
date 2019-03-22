#ifndef Exe3_2_BinModel02_h
#define Exe3_2_BinModel02_h

class BinModel
{
   private:
      double S0;
      double U;
      double D;
      double R;

   public:
      BinModel(double S0_, double U_, double D_, double R_)
         {S0=S0_; U=U_; D=D_; R=R_;}

      //computing risk-neutral probability
      double RiskNeutProb();

      //computing the stock price at node n,i
      double S(int n, int i);

      double GetR();
};

#endif
