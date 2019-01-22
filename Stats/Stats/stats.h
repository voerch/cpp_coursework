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
		double x_Squared;
};

class Stats2
{
	public:
		void add(double a, double b);
		double cov();
		double corr();
		void parameters();
		Stats2();

	private:
		Stats1 x;
		Stats1 y;
		double Sum;
		double NumberOfElements;

};