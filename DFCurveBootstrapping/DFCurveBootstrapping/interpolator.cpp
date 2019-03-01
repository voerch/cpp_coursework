//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#include <cmath>

#include "interpolator.h"
#include "error.h"

void LinearInterpolator::insert(double x, double y)
{
	//
	//	Determine whether x-coordinate already exists in the map.
	//	If it does, then new point should _override_ the old one.
	//
	map<double,double>::iterator it = mDataPoints.find(x);
	if ( it != mDataPoints.end() )
	{
		it->second = y;
		return;
	}
	else
	{
		const pair<double,double> p(x,y);
		mDataPoints.insert(p);
	}
}

double LinearInterpolator::value(double x) const
{
	map<double,double>::const_iterator it = mDataPoints.begin();

	if ( it == mDataPoints.end() )
	{
		fatalError("LinearInterpolator::value requires at least one point in the map");
	}

	if ( it->first > x )
	{
		//	Extrapolate flat on LHS
		return it->second;
	}
	++it;
	while ( it != mDataPoints.end() )
	{
		if ( it->first >= x )
		{
			const double x2 = it->first;
			const double y2 = it->second;
			--it;
			const double x1 = it->first;
			const double y1 = it->second;
			return ( (x2-x)*y1 + (x-x1)*y2 ) / (x2-x1);
		}
		++it;
	}
	//	Extrapolate flat on RHS
	--it;
	return it->second;
}

