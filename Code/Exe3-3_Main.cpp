#include <iostream>
using namespace std;

template<typename Type>
   void interchange(Type& x, Type& y)
{
   Type z;
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

   int m=-5;
   int n=2;
   cout << "before:" << endl;
   cout << "m = " << m << endl;
   cout << "n = " << n << endl;
   interchange(m,n);
   cout << "interchanged:" << endl;
   cout << "m = " << m << endl;
   cout << "n = " << n << endl;

   return 0;
}
