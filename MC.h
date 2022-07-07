#ifndef GUARD_MC_h
#define GUARD_MC_h
#include "SDE.h"
class MC {
private:
	SDE s;
	int times;
	double K;
	double r;
	char optType;
	std::istream& read(std::istream&);
public:
	MC(SDE ss) :s(ss), times(0), K(0.0), optType('C'), r(0.0) {}
	explicit MC(std::istream& is) { read(is); }
	double MC_simulation();
};
#endif // !GUARD_MC_h
