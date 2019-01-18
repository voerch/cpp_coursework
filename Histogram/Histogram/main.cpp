#include "Histogram.h"
#include "NRG.h"
#include <iostream>
#include <random>


using namespace std;

int main()
{
	Histogram h(-5,1,10);

	for (unsigned int i = 0; i < 10000; ++i) {
		h.add(rand()/RAND_MAX);
	}

	h.getResults();
	
	system("pause");
	return 0;
}