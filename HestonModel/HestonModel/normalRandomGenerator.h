//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#ifndef _NORMAL_RANDOM_GENERATOR_H_
#define _NORMAL_RANDOM_GENERATOR_H_

#include <cmath>
#include <stdlib.h>

class NormalRandomGenerator
{
public:

	NormalRandomGenerator() : m_isCalculated(false), m_value(0.0) {}
	virtual ~NormalRandomGenerator() {}

	double generate() const;

private:
	mutable bool m_isCalculated;
	mutable double m_value;
};

#endif