#include <iostream>
#include "stats.h"
#include "NRG.h"
using namespace std;

int main()
{
	NRG n;
	Stats1 s;

	for (int i = 0; i < 100000; ++i) {
		s.add(n.generate());
	}

	cout << s.mean() << endl;

	system("pause");
	return 0;

}