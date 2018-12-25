#include <iostream>
#include "Menus.h"
#include "Maths.h"
using namespace std;

int main() {

	const int FunctionChosen = PrintMenuAndGetOption();
	if (0 > FunctionChosen || FunctionChosen > 7)
		return 1;

	cout << "How many simulations do you wish to use?" << endl;
	int SimulationRequested;
	cin >> SimulationRequested;
	if (0 > SimulationRequested)
		return 1;


	double a  = CalculateIntegralMC(SimulationRequested, FunctionChosen);
	double b = CalculateIntegralExact(FunctionChosen);
	
	cout << "Monte Carlo integral :" << a;
	cout << "Exact integral :" << b;
	
	system("pause");
}