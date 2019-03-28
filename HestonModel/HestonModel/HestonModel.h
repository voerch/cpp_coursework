#ifndef HestonModel_h
#define HestonModel_h

using namespace std;
#include <vector>
#include <cstdlib>
#include <ctime>

typedef vector<double> SamplePath;

class HestonModel
{
   public:
	   double S0, r, sigma0Sq, sigmaSq, timestep, a, eta, rho;	

		HestonModel(double S0_, double r_, double sigma0Sq_, double sigmaSq_, double timestep_, double a_, double eta_, double rho_)
		{		
			S0 = S0_;
			r = r_; 
			sigma0Sq = sigma0Sq_;
			sigmaSq = sigmaSq_;
			timestep = timestep_;
			a = a_;
			eta = eta_;
			rho = rho_;
			
		}
      
		void GenerateSamplePath(double T,int m, SamplePath& S, SamplePath& V);
	
};

#endif
