#ifndef Options02_h
#define Options02_h

//inputting and displaying option data
int GetInputData(int* PtrN, double* PtrK);

//pricing European option
double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K);

//computing call payoff
double CallPayoff(double z, double K);

#endif
