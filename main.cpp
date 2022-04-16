#include <iostream>
#include "Headers/TPolinom.h"
#include "Headers/TMonom.h"
using namespace std;

void main() {
	TPolinom classObj;
	TMonom m;

	cout << "classObj 1 \nmonom 1: " << endl;
	cin >> m;
	classObj.AddMonom(m);

	cout << "monom 2: " << endl;
	cin >> m;
	classObj.AddMonom(m);

	cout << "monom 3: " << endl;
	cin >> m;
	classObj.AddMonom(m);

	TPolinom classObj1;
	cout << "classObj 2 \nmonom 1: " << endl;
	cin >> m;
	classObj1.AddMonom(m);

	cout << "monom 2: " << endl;
	cin >> m;
	classObj1.AddMonom(m);

	cout << "monom 3: " << endl;
	cin >> m;
	classObj1.AddMonom(m);

	classObj = classObj + classObj1;
	cout << classObj;
}