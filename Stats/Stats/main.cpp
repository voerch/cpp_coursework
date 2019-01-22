#include <iostream>
#include "stats.h"
#include <cmath>

using namespace std;

int main()
{
	Stats2 u;
	double GoodFit;

	u.add(1, 16);
	u.add(2, 11);
	u.add(3, 9);
	u.add(4, 3);
	u.add(5, 2);

	u.parameters();

	GoodFit = pow(u.corr(),2);
	cout << "Goodness of fit (R2) is: " << GoodFit << endl;

	system("pause");
	return 0;
}