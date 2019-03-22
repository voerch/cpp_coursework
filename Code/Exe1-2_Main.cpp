#include <iostream>
using namespace std;

void interchange(double& x, double& y)
{
   double z;
   z=x;
   x=y;
   y=z;
   return;
}

int main()
{
   double a=-3.3;
   double b=-4.1;
   cout << "before:" << endl;
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;
   interchange(a,b);
   cout << "interchanged:" << endl;
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;

   return 0;
}
