#include <iostream>
using namespace std;

template<typename Fct>
class DefInt
{
   private:
      double a,b;
      Fct MyFct;
   public:
      DefInt(double a_, double b_, Fct MyFct_)
         {a=a_; b=b_; MyFct=MyFct_;}
      double ByTrapezoid(int N);
      double BySimpson(int N);
};

template<typename Fct>
double DefInt<Fct>::ByTrapezoid(int N)
{
   double h=(b-a)/N;
   double Result=0.5*MyFct.f(a);
   for (int n=1; n<N; n++) Result+=MyFct.f(a+n*h);
   Result+=0.5*MyFct.f(b);
   return Result*h;
}

template<typename Fct>
double DefInt<Fct>::BySimpson(int N)
{
   double h=(b-a)/N;
   double Result=MyFct.f(a);
   for (int n=1; n<N; n++)
      Result+=4*MyFct.f(a+n*h-0.5*h)+2*MyFct.f(a+n*h);
   Result+=4*MyFct.f(b-0.5*h)+MyFct.f(b);
   return Result*h/6;
}

class Funct
{
   public:
      double f(double x){return x*x*x-x*x+1;}
};

int main()
{
   double a=1.0;
   double b=2.0;
   Funct f;
   DefInt<Funct> MyInt(a,b,f);
   int N=10;
   cout << "Trapeziodal approximation = "
        << MyInt.ByTrapezoid(N) << endl;
   cout << "Simpson approximation     = "
        << MyInt.BySimpson(N) << endl;
   return 0;
}
