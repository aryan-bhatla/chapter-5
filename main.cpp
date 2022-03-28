# include  <iostream >
# include  "matlib.h"
using namespace std;

int main() {

	double strike; 
	double timeToMaturity;
	double spot;
	double volatility;
	double riskFreeRate;

	cout << " Enter the strike price in AUD: ";
	cin >> strike;
	
	cout << " Enter the time to maturity in years: ";
	cin >> timeToMaturity; 

	cout << " Enter the spot price in AUD: ";
	cin >> spot; 

	cout << " Enter the volatility in percent (e.g. 20% = 0.2): ";
	cin >> volatility; 

	cout << " Enter the risk free interest rate in percent (e.g. 1% = 0.01): ";
	cin >> riskFreeRate;

	cout << " The Black Scholes Call Price for the given parameters is:  "	<< blackScholesCallPrice(strike,timeToMaturity,spot,volatility,riskFreeRate) << "\n";
	
	return 0;
}


