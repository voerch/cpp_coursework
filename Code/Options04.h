#ifndef Options04_h
#define Options04_h

#include "BinModel02.h"

//inputting and displaying option data
int GetInputData(int& N, double& K);

//pricing European option
double PriceByCRR(BinModel Model, int N, double K,
               double (*Payoff)(double z, double K));

//computing call payoff
double CallPayoff(double z, double K);

//computing put payoff
double PutPayoff(double z, double K);

#endif
