#ifndef GUARD_BS_h
#define GUARD_BS_h
#include <iostream>
class BS {
private:
	double S_0;
	double r;
	double K;
	double sigma;
	double T;
	double C_price;
	double P_price;
public:
	BS(std::istream& is) { read(is); }
	void cal_price();
	std::istream& read(std::istream&);
	double C_P() { return C_price; }
	double P_P() { return P_price; }
	double N(double);
};

#endif // !GUARD_BS_h

