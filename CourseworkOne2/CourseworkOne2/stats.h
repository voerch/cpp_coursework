#pragma once

class Stats1
{
	public:
		void add(double x);
		double mean();
		double StDev();

	private:
		double m_Sum = 0;
		double m_NumberOfElements = 0;
		double m_MinusMean = 0;
};