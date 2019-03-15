//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#include <cmath>
#include <stdlib.h>

#include "normalRandomGenerator.h"

double NormalRandomGenerator::generate() const
{
	const double TWO_PI = 6.2831853071795862;
	if (m_isCalculated)
	{
		m_isCalculated = false;
		return m_value;
	}
	else
	{
		const double u1 = (rand() + 0.5) / (RAND_MAX + 1.0);
		const double u2 = (rand() + 0.5) / (RAND_MAX + 1.0);

		const double r = sqrt(-2.0 * log(u1));
		const double arg = TWO_PI * u2;
		m_value = r * cos(arg);
		m_isCalculated = true;
		return r * sin(arg);
	}
}

