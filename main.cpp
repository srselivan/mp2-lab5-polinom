#include <iostream>
#include "Headers/TPolinom.h"
#include "Headers/TMonom.h"
using namespace std;

void main() {
	TPolinom classObj;
	classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(1, 2, 1, 1));

	TPolinom classObj1;
	classObj1.AddMonom(TMonom(1, 1, 1, 1));
	classObj1.AddMonom(TMonom(1, 2, 1, -1));

	classObj = classObj + classObj1;
	cout << classObj;
}