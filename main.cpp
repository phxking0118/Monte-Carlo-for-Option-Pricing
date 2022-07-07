#include"MC.h"
#include"BS.h"
#include <iostream>
using namespace std;
int main() {
	MC mc(cin);
	cout << mc.MC_simulation() << endl;
	BS bs(cin);
	bs.cal_price();
	cout << bs.C_P();
}