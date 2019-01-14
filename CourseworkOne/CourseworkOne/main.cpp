#include "stats.h"
#include <iostream>
using namespace std;

int main()
{
	Stats1 s;

	s.add(1.1);
	s.add(2.2);
	s.add(3.3);
	cout << s.mean() << endl;

	s.add(4.4);
	cout << s.mean() << endl;

	for (int i = 1; i <= 1000; ++i)
	{
		s.add(rand()/(double)RAND_MAX);
	}
	cout << s.mean() << endl;


	Stats2 j;

	j.add(5.0, 15.0);




	system("pause");

	return 0;
}