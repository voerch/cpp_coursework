#pragma once
#include <vector>
using namespace std;

typedef vector<double> SamplePaths;

class JDModel 
{
	double S0, sigma, s, m, lambda;

public:
	virtual ~JDModel() {};
	JDModel(double S0_, double sigma_, double r_, double s_, double m_, double lambda_)
	{
		S0 = S0_;
		r = r_;
		sigma = sigma_;
		s = s_;
		m = m_;
		lambda = lambda_;
	}
	double r;
	void GenerateSamplePaths(SamplePaths& SP, double T, int samplingDates, int nPaths);
};
