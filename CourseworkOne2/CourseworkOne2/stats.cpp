#include "stats.h"
#include <cmath>

void Stats1::add(double x) 
{
	m_Sum += x;
	m_NumberOfElements += 1;
	m_MinusMean += pow(x - (m_Sum / m_NumberOfElements), 2);
}

double Stats1::mean()
{
	return m_Sum / m_NumberOfElements;;
}

double Stats1::StDev()
{
	return sqrt(m_MinusMean / m_NumberOfElements);
}