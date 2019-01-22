#pragma once

class Stats1
{
	public:
		void add(double x);
		double mean();
		double stdev();
		Stats1();

	private:
		double Sum;
		double NumberOfElements;
		double MinusMean;
};

class Stats2
{
	public:
		void add(double a, double b);
		double cov();
		double corr();
		Stats2();
		void parameters();

	private:
		Stats1 x;
		Stats1 y;
		double Sum;
		double NumberOfElements;
		double covariance;
		double m;
		double c;
};