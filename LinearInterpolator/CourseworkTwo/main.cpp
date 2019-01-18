#include <iostream>
#include "LI.h"

int main() 
{
	LinearInterpolator li;

	li.add(1, 1.07);
	li.add(2, 1.82);
	li.add(5, 2.57);
	li.add(3, 2.3);
	li.add(7, 2.89);
	li.add(10, 3.01);

	std::cout << li.value(8) << std::endl;


	system("pause");
	return 0;

}