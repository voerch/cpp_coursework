#include "JDModel.h"
#include <random>

const double PI = 4 * atan(1.0);
using namespace std;
double Gauss()
{
	double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
	double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

	return sqrt(-2 * log(U1)) * cos(2 * PI * U2);
}


void JDModel::GenerateSamplePaths(SamplePaths& SP, double T, int samplingDates, int nPaths)
{
	double timeStep = T / samplingDates;
	double alpha = r - (pow(sigma, 2) / 2) - (lambda * (exp(m + (pow(s, 2) / 2)) - 1));
	double drift = (alpha * timeStep);
	double vol = sigma * sqrt(timeStep);
	SP.reserve(nPaths);
	for (int i = 0; i < nPaths; i++)
	{
		double S = S0;
		for (int k = 0; k < samplingDates; k++)
		{
			S = S * exp(drift + (vol * Gauss()));

			std::random_device device;
			std::mt19937 generator(device());
			std::uniform_real_distribution<double> distribution(0.0, 1.0);

			double u = distribution(generator);
			if (u <= lambda * timeStep)
			{
				S *= exp(m + s * Gauss());
			}
		}
		SP.push_back(S);
	}
}