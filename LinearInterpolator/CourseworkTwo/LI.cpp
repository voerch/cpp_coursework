#include "LI.h"
#include <map>
#include <iostream>

using namespace std;

void LinearInterpolator::add(double x, double y)
{
	swap.insert(pair<double,double>(x, y));
}

double LinearInterpolator::value(double x)
{
	double result, x1, x2, y1, y2;

	map<double, double>::iterator it1, it2;
	it1 = swap.lower_bound(x);
	it2 = it1;
	it2--;

	x1 = it1->first;
	x2 = it2->first;
	y1 = it1->second;
	y2 = it2->second;
	result = y1 + ((x - x1) * (y2 - y1) / (x2 - x1));

	return result;
}
