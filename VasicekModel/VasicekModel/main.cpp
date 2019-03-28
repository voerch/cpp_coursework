#include <iostream>
#include "VasicekModel.h"
#include "Stats.h"
using namespace std;

int main()
{
	double a = 0.25, b = 0.1, sigma = 0.02, r = 0.07;
	double T = 5;
	int timeSplit = 252;
	int nPaths = 1000;
	double TimeStep = T / timeSplit;
	double Sum = 0;
	VasicekModel Model(a, b, sigma, r);
	SamplePath R;
	Stats Stat;

	for (int i = 0; i < nPaths; i++) 
	{
		Model.GenerateSamplePath(R, T, timeSplit);
		for (SamplePath::iterator it = R.begin(); it < R.end(); it++)
		{
			Sum += *it;
		}
		Stat.add(exp(-Sum * TimeStep));
	}

	cout << "price: " << Stat.mean() << endl << "error: " << Stat.stDev() / sqrt(double(nPaths)) << endl;
	system("pause");
	return 0;
}