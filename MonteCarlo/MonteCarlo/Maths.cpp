#include <math.h>
#include <cstdlib>
double Function(double x, int FunctionChosen);
double CalculateIntegralMC(int NumberOfSimulations, int FunctionChosen) {


	double SumOfValues=0;
	for (int iSimulation=0; iSimulation < NumberOfSimulations-1; iSimulation++) {
		double x = double(rand()) / RAND_MAX;
		SumOfValues += Function(x, FunctionChosen);
	}

	return SumOfValues / NumberOfSimulations;
}


double Function(double x, int FunctionChosen) {
	switch (FunctionChosen) {
	case 1:
		break;
	case 2:
		x = pow(x, 2);
		break;
	case 3:
		x = sin(x);
		break;
	case 4:
		x = cos(x);
		break;
	case 5:
		x = exp(x);
		break;
	}
	return x;
}

double CalculateIntegralExact(int FunctionChosen) {
	double exact=0;
	switch (FunctionChosen) {
	case 1:
		exact = 0.5;
		break;
	case 2:
		exact = 1/3;
		break;
	case 3:
		exact = -cos(1) + cos(0);
		break;
	case 4:
		exact = sin(1) - sin(0);
		break;
	case 5:
		exact = exp(1)-1;
		break;
	}
	return exact;
}