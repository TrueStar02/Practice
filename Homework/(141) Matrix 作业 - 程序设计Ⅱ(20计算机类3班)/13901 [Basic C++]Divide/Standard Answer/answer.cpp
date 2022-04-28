#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << a / b << endl << fixed << setprecision(2) << (double) a / (double) b << endl;
	return 0;
}