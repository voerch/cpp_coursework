#ifndef BinModel01_h
#define BinModel01_h

//computing risk-neutral probability
double RiskNeutProb(double U, double D, double R);

//computing the stock price at node n,i
double S(double S0, double U, double D, int n, int i);

//inputting, displaying and checking model data
int GetInputData(double& S0,
                 double& U, double& D, double& R);

#endif
