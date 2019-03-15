//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#include <cmath>

#include "stats.h"

void Stats1::add(double x)
{
	mSum += x;
	mSum2 += x * x;
	mCount++;
	return;
}

unsigned long Stats1::count() const
{
	return mCount;
}

double Stats1::mean() const
{
	if (mCount == 0)
		fatalError("Stats1::mean() requires 1 or more points");
	return mSum / static_cast<double>(mCount);
}

double Stats1::stdevP() const
{
	if (mCount == 0)
		fatalError("Stats1::stdevP() requires 1 or more points");
	const double m = mean();
	return sqrt(mSum2 / mCount - m * m);
}


//****************************************************************

void Stats2::add(double x, double y)
{
	mX.add(x);
	mY.add(y);
	mSumXY += x * y;
	return;
}

unsigned long Stats2::count() const
{
	return mX.count();
}

double Stats2::covariance() const
{
	if (count() == 0)
		fatalError("Stats2::covariance() requires 1 or more points");
	const double cov = mSumXY / count() - mX.mean() * mY.mean();
	return cov;
}

double Stats2::correlation() const
{
	if (count() < 2)
		fatalError("Stats2::correlation() requires 2 or more points");
	const double cov = covariance();
	const double denom = mX.stdevP() * mY.stdevP();
	if (denom == 0.0)
		fatalError("Stats2::correlation() returns infinity");
	return cov / denom;
}

double Stats2::gradient() const
{
	if (count() < 2)
		fatalError("Stats2::gradient() requires 2 or more points");
	const double cov = covariance();
	const double varX = mX.stdevP() * mX.stdevP();
	if (varX == 0.0)
		fatalError("Stats2::gradient() returns infinity");
	return cov / varX;
}

double Stats2::intercept() const
{
	if (count() < 2)
		fatalError("Stats2::intercept() requires 2 or more points");
	return mY.mean() - gradient() * mX.mean();
}
