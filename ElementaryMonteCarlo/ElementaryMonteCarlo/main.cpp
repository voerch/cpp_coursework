#include <iostream>
#include <cmath>
#include <random>
#include "stats.h"
using namespace std;

int main()
{
	mt19937 generator(123);
	uniform_real_distribution<double> dis(0.0, 4.0);
	Stats1 InAndOut;
	int N = 0;
	for (int i = 0; i < 100000000; i++)
	{
		N += 1;
		double x = dis(generator);
		double y = dis(generator);

		double r = sqrt(pow(x, 2) + pow(y, 2));
		double theta = atan(y / x);

		if (r <= 3 - cos(8 * theta))
			InAndOut.add(1);
		else
			InAndOut.add(0);

		double error = InAndOut.stdevP() / sqrt(N-1) * 64;
		if (error < 0.01) 
		{
			cout << InAndOut.mean() * 64 << endl;
			cout << error << endl;
			cout << N << endl;
			break;
		}
	}


	system("pause");
	return 0;
}