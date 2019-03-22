#include <iostream>
using namespace std;

class DefInt
{
   private:
      double a,b;
      double (*f)(double x);
   public:
      DefInt(double a_, double b_, double (*f_)(double x))
         {a=a_; b=b_; f=f_;}
      double ByTrapezoid(int N);
      double BySimpson(int N);
};

double DefInt::ByTrapezoid(int N)
{
   double h=(b-a)/N;
   double Result=0.5*f(a);
   for (int n=1; n<N; n++) Result+=f(a+n*h);
   Result+=0.5*f(b);
   return Result*h;
}

double DefInt::BySimpson(int N)
{
   double h=(b-a)/N;
   double Result=f(a);
   for (int n=1; n<N; n++) Result+=4*f(a+n*h-0.5*h)+2*f(a+n*h);
   Result+=4*f(b-0.5*h)+f(b);
   return Result*h/6;
}

double f(double x){return x*x*x-x*x+1;}

int main()
{
   double a=1.0;
   double b=2.0;
   DefInt MyInt(a,b,f);
   int N=10;
   cout << "Trapeziodal approximation = "
        << MyInt.ByTrapezoid(N) << endl;
   cout << "Simpson approximation     = "
        << MyInt.BySimpson(N) << endl;
   return 0;
}
