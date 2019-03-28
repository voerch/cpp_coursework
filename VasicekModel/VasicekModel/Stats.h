#pragma once

class Stats
{
	double Sum, SumSquared, Count;

public:
	~Stats() {};
	Stats() : Sum(0), SumSquared(0), Count(0) {};
	void add(double x);
	double mean();
	double stDev();
};