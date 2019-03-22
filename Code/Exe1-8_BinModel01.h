#ifndef Exe1_8_BinModel01_h
#define Exe1_8_BinModel01_h

//computing risk-neutral probability
double RiskNeutProb(double U, double D, double R);

//computing the stock price at node n,i
double S(double S0, double U, double D, int n, int i);

//inputting, displaying and checking model data
int GetInputData(double* pS0,
                 double* pU, double* pD, double* pR);

#endif
