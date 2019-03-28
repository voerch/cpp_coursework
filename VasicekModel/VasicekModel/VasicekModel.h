#pragma once
#include <vector>
using namespace std;

typedef vector<double> SamplePath;

class VasicekModel
{
	double a, b, sigma, r;
public:
	~VasicekModel() {};
	VasicekModel(double a_, double b_, double sigma_, double r_) :
		a(a_), b(b_), sigma(sigma_), r(r_) {};
	void GenerateSamplePath(SamplePath& S, double T, int timeSplit);


};