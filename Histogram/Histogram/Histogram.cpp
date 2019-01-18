#include "Histogram.h"
#include <iostream>

using namespace std;

void Histogram::add(double x)
{
	int size = hist.size()-2;
	if (x > xmax)
		hist[size+1] += 1;
	else if (x < xmin)
		hist[0] += 1;
	else
		hist[int(x) % (size-2)] += 1;
}

void Histogram::getResults()
{
	for (unsigned int i = 0; i < hist.size(); ++i)
	{
		cout << "Element number " << i << " has value " << hist[i] << endl;
	}

}

Histogram::Histogram(double xmi, double xma, unsigned int nBin) 
{
	for (unsigned int i = 0; i < nBin + 2; i++) 
		hist.push_back(0);
	
	xmin = xmi;
	xmax = xma;
	cout << hist.size();

}
