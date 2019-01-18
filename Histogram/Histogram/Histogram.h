#pragma once
#include <vector>

using namespace std;

class Histogram 
{
	public:
		Histogram(double xmi, double xma, unsigned int nBin);
		void add(double x);
		void getResults();

	private:
		vector<int>hist;
		double xmin, xmax;

};