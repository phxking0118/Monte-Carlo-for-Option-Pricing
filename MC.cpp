#include"MC.h"
#include <algorithm>
#include <cmath>
using namespace std;
double MC::MC_simulation() {
	cout << "How many times would you like to iterate?(Enter an integer)";
	cin >> times;
	double sum = 0;
	for (int i = 0; i != times; ++i) {
		if (optType == 'C')
			sum += max(s.Solve_Euler()-K,0.0);
		else
			sum += max(K - s.Solve_Euler(), 0.0);
	}
	double optPrice_T = sum / times;
	double optPrice_0 = optPrice_T * exp(-s.time_spread() * r);
	return optPrice_0;
}
istream& MC::read(istream& is) {
	s.read(is);
	cout << "Now initialize the parameters of the option:";
	cout << "Enter Strike Price, the type of option(C/P) and the risk free rate";
	cin >> K >> optType >> r;
	return is;
}
