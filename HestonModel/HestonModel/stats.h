//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#ifndef _STATS_H_
#define _STATS_H_

#include "error.h"

class Stats1
{
public:
	Stats1() : mCount(0), mSum(0.0), mSum2(0.0) {};
	virtual ~Stats1() {};

	void add(double x);

	unsigned long count() const;
	double mean() const;
	double stdevP() const;

private:
	unsigned long mCount;
	double mSum;
	double mSum2;
};

class Stats2
{
public:
	Stats2() : mSumXY(0.0) {};
	~Stats2() {};
	void add(double x, double y);
	unsigned long count() const;

	double covariance() const;
	double correlation() const;

	//
	//	Least-squares fit
	//
	double gradient() const;
	double intercept() const;

private:
	Stats1 mX, mY;
	double mSumXY;
};

#endif
