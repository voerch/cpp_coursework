#include "HestonModel.h"
#include <cmath>

const double pi=4.0*atan(1.0);

double Gauss()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}

double CorrelatedGauss(double first, double rho)
{
	return first * rho + sqrt(1 - pow(rho, 2)) * Gauss();
}


void HestonModel::GenerateSamplePath(double T, int m, SamplePath& S)
{
   SamplePath Vol(m);
   double v0 = sigma0Sq;
   double v = sigmaSq;
   double St = S0;

   for (int k = 0; k<m; k++)
   {
	   double firstRandom = Gauss();
	   double secondRandom = CorrelatedGauss(firstRandom, rho);

	   Vol[k] = pow(sqrt(v0) + (eta / 2 * sqrt(timestep) * secondRandom), 2) - (a * (v0 - v) * timestep) - (pow(eta, 2) / 4 * timestep);
	   S[k] = St * exp(((r - (v0 * 0.5)) * timestep) + (sqrt(v0 * timestep) * firstRandom));
	   v0 = Vol[k];
	   St = S[k];
   }
}

