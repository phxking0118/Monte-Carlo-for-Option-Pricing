#include"SDE.h"
#include <boost/random.hpp>
#include <iostream>
#include <ctime>
using namespace std;
istream& SDE::read(istream& is) {
	cout << "Now initialize the parameters of a SDE." << endl;
	cout << "Enter elements in order:" << endl;
	cout << "Stock Price at time 0; Drift Parameter; Volatility Parameter; Time_Spread:";
	is >> X_0 >> alpha >> sigma >> T;
	X_T = 0.0;
	step = 0;
	return is;
}
double SDE::Solve_Euler() {
	if (step == 0) {
		cout << "How many step do you wish to set?(Enter an integer)";
		cin >> step;
	}
	double interval = T / step;
	double mean = 0;
	double std = interval;
	boost::lagged_fibonacci607 rng;
	rng.seed(static_cast<boost::uint32_t> (std::time(0)));
	boost::normal_distribution<> myNormal(mean, std);
	boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<>>
		NormalRng(rng, myNormal);
	X_T = X_0 + alpha * X_0 * interval + sigma * X_0 * NormalRng();
	for (int i = 1; i != step; ++i) {
		X_T = X_T + alpha * X_T * interval + sigma * X_T * NormalRng();
	}
	return X_T;
}