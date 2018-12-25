#include <iostream>
using namespace std;

int PrintMenuAndGetOption() {
	cout << "1. f(x) = x\n 2. f(x) = x ^ 2\n 3. f(x) = sin(x)\n4. f(x) = cos(x)\n5. f(x) = exp(x)\n6. Exit \nPlease choose a function to integrate : " << endl;

	int option;
	cin >> option;
	return option;
}