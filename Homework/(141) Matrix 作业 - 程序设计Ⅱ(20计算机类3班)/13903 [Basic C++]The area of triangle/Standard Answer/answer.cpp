#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double xA, yA, xB, yB;
	
	xA = x1 - x2; yA = y1 - y2;
	xB = x3 - x2; yB = y3 - y2;
	
	double area = fabs(xA * yB - xB * yA) * 0.5;
	
	cout << fixed << setprecision(2) << area << endl;
	return 0;
}