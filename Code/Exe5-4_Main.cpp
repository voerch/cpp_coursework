#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const double pi=4.0*atan(1.0);

double Gauss()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}

void ExpectationDirect(long N)
{
   double H=0.0, Hsq=0.0;
   double X;
   for (long i=0;i<N;i++)
   {
      X=cos(0.5*Gauss());
      H=(i*H + X)/(i+1.0);
      Hsq=(i*Hsq + X*X)/(i+1.0);
   }
   cout << "Expectation computed directly: " << endl
   << "E(X)  = " << H << endl
   << "error = " << sqrt(Hsq-H*H)/sqrt(N-1.0) << endl << endl;
}

void ExpectationCV(long N)
{
   double H=0.0, Hsq=0.0;
   double X, Y, Z;
   for (long i=0;i<N;i++)
   {
      Z=0.5*Gauss();
      Y=1.0-0.5*Z*Z;
      X=cos(Z);
      H=(i*H + X-Y)/(i+1.0);
      Hsq=(i*Hsq + (X-Y)*(X-Y))/(i+1.0);
   }
   cout << "Expectation with CV: " << endl
   << "E(X)  = " << H + 7.0/8.0 << endl
   << "error = " << sqrt(Hsq-H*H)/sqrt(N-1.0) << endl << endl;
}

int main()
{
   srand(time(NULL));
   long N = 100000;
   ExpectationDirect(N);
   ExpectationCV(N);
}
