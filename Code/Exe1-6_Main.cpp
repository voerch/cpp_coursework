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

void bubblesort(double a[], int N)
{
   for (int i=1; i<N; i++)
   {
      for (int j=1; j<=N-i; j++)
      {
         if (a[j-1]>a[j]) interchange(a[j-1],a[j]);
      }
   }
}

int main()
{
   int SequenceLength=5;
   double Sequence[SequenceLength];
   Sequence[0]=8.2;
   Sequence[1]=3.6;
   Sequence[2]=9.1;
   Sequence[3]=1.2;
   Sequence[4]=4.5;

   cout << "before: " << endl;
   for (int n=0; n<SequenceLength; n++) cout << Sequence[n] << endl;
   cout << endl;

   bubblesort(Sequence,SequenceLength);

   cout << "after:"  << endl;
   for (int n=0; n<SequenceLength; n++) cout << Sequence[n] << endl;
   cout << endl;

   return 0;
}
