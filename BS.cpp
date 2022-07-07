#include "BS.h"
#include<cmath>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
using namespace std;
using namespace boost::math;
void BS::cal_price() {
	double d1 = (log(S_0 / K) + (r + sigma*sigma/2) * T) / (sigma * sqrt(T));
	double d2 = d1 - sigma * sqrt(T);
	C_price = S_0 * N(d1) - K * exp(-r * T) * N(d2);
	P_price = K * exp(-r * T) * N(-d2) - S_0 * N(-d1);
}
istream& BS::read(istream& is) {
	cout << "Enter S_0,r,K,sigma,T";
	cin >> S_0 >> r >> K >> sigma >> T;
	return is;
}
double BS::N(double d) {
	normal_distribution<> myNormal(0.0, 1.0);
	return cdf(myNormal, d);
}
