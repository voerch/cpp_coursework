#ifndef Exe1_11_Options03_h
#define Exe1_11_Options03_h

//inputting and displaying option data
int GetInputData(int& N, int NoOfParams, double Params[]);

//pricing European option by CRR formula
double PriceByCRR(double S0, double U, double D,
   double R, int N, double Params[],
   double (*Payoff)(double z, double Params[]));

//coumputing call payoff
double CallPayoff(double z, double Params[]);

//coumputing put payoff
double PutPayoff(double z, double Params[]);

//coumputing double-digital call payoff
double DoubDigitPayoff(double z, double Params[]);

#endif
