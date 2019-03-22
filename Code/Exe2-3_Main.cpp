#include <iostream>
using namespace std;

class DefInt
{
   private:
      double a,b;
   public:
      DefInt(double a_, double b_){a=a_; b=b_;}
      virtual double f(double x)=0;
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
   for (int n=1; n<N; n++)
      Result+=4*f(a+n*h-0.5*h)+2*f(a+n*h);
   Result+=4*f(b-0.5*h)+f(b);
   return Result*h/6;
}

class DefIntFunct: public DefInt
{
   public:
      DefIntFunct(double a_, double b_):DefInt(a_,b_){}
      double f(double x){return x*x*x-x*x+1;}
};

int main()
{
   double a=1.0;
   double b=2.0;
   DefIntFunct MyInt(a,b);
   int N=10;
   cout << "Trapeziodal approximation = "
        << MyInt.ByTrapezoid(N) << endl;
   cout << "Simpson approximation     = "
        << MyInt.BySimpson(N) << endl;
   return 0;
}
