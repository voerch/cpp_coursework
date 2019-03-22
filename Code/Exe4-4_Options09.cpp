#include "Exe4-4_Options09.h"
#include "BinModel02.h"
#include "BinLattice02.h"
#include <iostream>
#include <cmath>
using namespace std;

int Call::GetInputData()
{
   cout << "Enter call option data:" << endl;
   cout << "Enter steps to expiry N: "; cin >> N;
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double Call::Payoff(double z)
{
   if (z>K) return z-K;
   return 0.0;
}

int Put::GetInputData()
{
   cout << "Enter put option data:" << endl;
   cout << "Enter steps to expiry N: "; cin >> N;
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;
   return 0;
}

double Put::Payoff(double z)
{
   if (z<K) return K-z;
   return 0.0;
}
