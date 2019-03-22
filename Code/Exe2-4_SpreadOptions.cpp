#include "Exe2-4_SpreadOptions.h"
#include <iostream>
using namespace std;

int StrangleOpt::GetInputData()
{
   cout << "Enter European strangle option data:" << endl;
   int N;
   cout << "Enter steps to expiry N: "; cin >> N; SetN(N);
   cout << "Enter parameter K1:      "; cin >> K1;
   cout << "Enter parameter K2:      "; cin >> K2;
   cout << endl;
   cout << "N  = " << N << endl;
   cout << "K1 = " << K1 << endl;
   cout << "K2 = " << K2 << endl;
   cout << endl;
   return 0;
}

double StrangleOpt::Payoff(double z)
{
   if (z<=K1) return K1-z;
   else if (K2<z) return z-K2;
   return 0.0;
}

int ButterflyOpt::GetInputData()
{
   cout << "Enter European butterfly spread option data:" << endl;
   int N;
   cout << "Enter steps to expiry N: "; cin >> N; SetN(N);
   cout << "Enter parameter K1:      "; cin >> K1;
   cout << "Enter parameter K2:      "; cin >> K2;
   cout << endl;
   cout << "N  = " << N << endl;
   cout << "K1 = " << K1 << endl;
   cout << "K2 = " << K2 << endl;
   cout << endl;
   return 0;
}

double ButterflyOpt::Payoff(double z)
{
   if (K1<z && z<=(K1+K2)/2) return z-K1;
   else if ((K1+K2)/2<z && z<=K2) return K2-z;
   return 0.0;
}
