#ifndef GUARD_SDE_h
#define GUARD_SDE_h
#include <iostream>
class SDE {
private:
    double X_0;
    double alpha;
    double sigma;
    double T;
    double X_T;
    int step;
public:
    SDE() :X_0(0.0), alpha(0.0), sigma(0.0), T(1.0),X_T(0.0),step(0) {}
    ~SDE() {}
    double time_spread() { return T; }
    explicit SDE(std::istream& is) { read(is); }
    double Solve_Euler();
    std::istream& read(std::istream&);
};
#endif // !GUARD_SDE_h

