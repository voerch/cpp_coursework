#include "Exe1-10_DigitalPut.h"

double DigitalPutPayoff(double z, double K)
{
   if (z<K) return 1.0;
   return 0.0;
}
