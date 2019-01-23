#include <iostream>
#include "../../Stats/Stats/stats.h"
#include "NRG.h"

int main()
{
	Stats1 st;
	NRG n;

	for (int i = 0; i < 100000; ++i) 
		st.add(n.generate());

	std::cout << st.mean() << std::endl;
	std::cout << st.stdev() << std::endl;

	system("pause");
	return 0;
}