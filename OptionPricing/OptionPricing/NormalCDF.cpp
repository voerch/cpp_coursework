#include <math.h>

double CumulativeNormalDistribution(double d)
{
	const double A1 = 0.31938153;
	const double A2 = -0.356563782;
	const double A3 = 1.781477937;
	const double A4 = -1.821255978;
	const double A5 = 1.330274429;
	const double RSQRT2PI = 0.398942280401432677939946;
	const double K = 1.0 / (1.0 + 0.2316419	* fabs(d));
	double cnd = RSQRT2PI
		*
		exp(-0.5*d*d)*(K*(A1 + K*(A2 + K*(A3 + K*(A4 + K*A5)))));
	if (d > 0)
		cnd	= 1.0 - cnd;
	return
		cnd;
}