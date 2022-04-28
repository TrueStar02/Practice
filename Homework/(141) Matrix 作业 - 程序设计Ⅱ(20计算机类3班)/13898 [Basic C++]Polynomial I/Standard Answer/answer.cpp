#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << a * c << "x^2+" << a * d + b * c << "x+" << b * d << endl;
	return 0;
}