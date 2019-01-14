#pragma once

class Stats1
{
	public:
		void add(double x);
		double mean();
		double StDev();

	private:
		Stats1();
		double Sum;
		double NumberOfElements;
		double MinusMean;
};

class Stats2
{

	public:
		void add(double x, double y);
		double Covariance();
		double Correlation();

	private:
		double SumXY = 0;
		double NumberOfElements = 0;
		double MinusMeanX = 0;
		double MinusMeanY = 0;
		double Cov;
		double SumX = 0;
		double SumY = 0;
};