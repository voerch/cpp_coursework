//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#ifndef _INTERPOLATOR_H_
#define _INTERPOLATOR_H_

#include <map>

using namespace std;

class LinearInterpolator
{
public:
	LinearInterpolator() {};
	virtual ~LinearInterpolator() {};
	
	void insert(double x, double y);
	double value(double x) const;

private:
	map<double,double> mDataPoints;
};

#endif