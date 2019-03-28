#include <iostream>
#include <fstream>
#include "EurOption.h"
#include <vector>
#include <iomanip>

using namespace std;

class Hold
{

public:
	Hold(EurOption* Opt, int Quantity_) : Option(Opt), Quantity(Quantity_) {};
	//virtual ~Hold() {
	//	delete Option;
	//};

	double Price(double S0, double r, double sigma)
	{
		return Quantity * Option->PriceByBS(S0, r, sigma);
	}

	double Delta(double S0, double r, double sigma)
	{
		return Quantity * Option->PriceDelta(S0, r, sigma);
	}

	double Gamma(double S0, double r, double sigma)
	{
		return Quantity * Option->PriceGamma(S0, r, sigma);
	}

	double Theta(double S0, double r, double sigma)
	{
		return Quantity * Option->PriceTheta(S0, r, sigma);
	}
private:
	EurOption* Option;
	int Quantity;
};

int main()
{

	char CallPutFlag;
	int Quantity;
	double Strike;
	double TimeToExpiry;

	double S0 = 100.0;
	double sigma = 0.3;
	double r = 0.04;

	ifstream in("data.txt");
	ofstream out("output.txt");

	if (!in || !out)
	{
		cout << "Cannot open file." << endl;
		return 1;
	}

	int counter = 1;
	vector<Hold> options;
	
	while (!in.eof()) {
		in >> CallPutFlag >> Quantity >> Strike >> TimeToExpiry;

		EurOption* option;
		option = new Call(Strike, TimeToExpiry);
		options.push_back(Hold(option,Quantity));
	}

	out << setw(10) << "Option" << setw(10) << "Price" << setw(10) << "Delta" << setw(10) << "Gamma" << setw(10) << "Theta" << endl;
	for (vector<Hold>::iterator it = options.begin(); it != options.end(); ++it, counter++)
	{
		out << setw(10) << counter << setw(10) << it->Price(S0, r, sigma) << setw(10) << it->Delta(S0, r, sigma) << setw(10) << it->Gamma(S0, r, sigma) << setw(10) << it->Theta(S0, r, sigma) << endl;
	}

	system("pause");
	return 0;
}

