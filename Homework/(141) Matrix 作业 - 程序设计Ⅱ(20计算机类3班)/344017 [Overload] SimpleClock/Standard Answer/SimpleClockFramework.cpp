#include "SimpleClock.h"


int main() {
	
	Clock clock1;
	cin >> clock1;
	cout << "cin >> clock1" << endl;
	cout << ">> clock1 ---- " << clock1 << endl << endl;
	
	Clock clock2(clock1);
	cout << "clock2(clock1)" << endl;
	cout << ">> clock1 ---- " << clock1 << endl;
	cout << ">> clock2 ---- " << clock2 << endl << endl;
	
	Clock clock3 = clock1 ++;
	Clock clock4 = ++ clock2;
	cout << "clock3 = clock1 ++" << endl;
	cout << "clock4 = ++ clock2" << endl;
	cout << ">> clock1 ---- " << clock1 << endl;
	cout << ">> clock2 ---- " << clock2 << endl;
	cout << ">> clock3 ---- " << clock3 << endl;
	cout << ">> clock4 ---- " << clock4 << endl << endl;
	
	Clock clock5(11, 45, 14);
	Clock clock6 = clock1 + clock5;
	cout << "clock5(11, 45, 14)" << endl;
	cout << "clock6 = clock1 + clock5" << endl;
	cout << ">> clock1 ---- " << clock1 << endl;
	cout << ">> clock5 ---- " << clock5 << endl;
	cout << ">> clock6 ---- " << clock6 << endl << endl;
	
	Clock clock7;
	clock7 += clock5;
	clock7 += clock6;
	cout << "clock7()" << endl;
	cout << "clock7 += clock5" << endl;
	cout << "clock7 += clock6" << endl;
	cout << ">> clock5 ---- " << clock5 << endl;
	cout << ">> clock6 ---- " << clock6 << endl;
	cout << ">> clock7 ---- " << clock7 << endl;

	return 0;
}
