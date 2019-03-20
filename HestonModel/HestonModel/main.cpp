#include <iostream>
#include "EurOption.h"
#include "Solver03.h"

using namespace std;
class Intermediary : public CallOption
{
private:
	double S0, r, sigma0Sq, sigmaSq, timestep, a, eta, rho, epsilon;
	long N;
public:
	Intermediary(double T_, double K_, int m_, long N_, double epsilon_, double S0_, double r_, double sigmaSq_, double timestep_, double a_, double eta_, double rho_) :CallOption(T_, K_, m_)
	{
		S0 = S0_;
		r = r_;
		sigmaSq = sigmaSq_;
		timestep = timestep_;
		a = a_;
		eta = eta_;
		rho = rho_;
		N = N_;
		epsilon = epsilon_;
	}

	double Value(double sigma0Sq)
	{
		HestonModel Model(S0, r, sigma0Sq, sigmaSq, timestep, a, eta, rho);
		return PriceByMC(Model, N, epsilon);
	}
	double Deriv(double sigma0Sq)
	{
		return 0;
	}
};

int main()
{
   double S0=100.0, r=0.05, sigma0Sq=0.04, sigmaSq = 0.09, timestep = 1.0/365.0, a = 1.25, eta = 0.3, rho = 0.1;
   HestonModel Model(S0, r, sigma0Sq, sigmaSq, timestep, a, eta, rho);

   double T=1.0, K=105.0;
   int m=365;

   CallOption Opt(T, K, m);

   long N=10000;
   double epsilon = 0.001;
   //Opt.VegaByMC(Model, N, epsilon);
   Opt.PriceByMC(Model, N, epsilon);
   
   Intermediary func(double T, double K, int m, long N, double epsilon, double S0, double r, double sigmaSq, double timestep, double a, double eta, double rho);

   double Acc = 0.001;
   double LEnd = 0.01, REnd = 1.0;
   double Tgt = 12.56;
   std::cout << "Implied vol by bisect: " << SolveByBisect(&func, Tgt, LEnd, REnd, Acc) << endl;

   system("pause");
   return 0;
}
