#include <iostream>
#include "Headers/TPolinom.h"
#include "Headers/TMonom.h"
using namespace std;

void main() {
	TPolinom classObj;
	/*classObj.AddMonom(TMonom(1, 1, 1, 1));
	classObj.AddMonom(TMonom(1, 2, 1, 1));
	classObj.AddMonom(TMonom(105, 2, 9, 1));
	classObj.AddMonom(TMonom(504, 2, 3, 3));
	cout << classObj << endl;

	TPolinom classObj1;
	classObj1.AddMonom(TMonom(1, 1, 1, 1));
	classObj1.AddMonom(TMonom(-1, 2, 1, 1));
	classObj1.AddMonom(TMonom(-105, 2, 9, 1));
	classObj1.AddMonom(TMonom(5, 2, 3, 3));
	cout << classObj1 << endl;

	classObj = classObj1 + classObj;*/
	TMonom m(1, 1, 1, 1);
	classObj.AddMonom(m);
	cout << classObj.ToString();
}