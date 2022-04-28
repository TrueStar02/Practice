#include <iostream>

using namespace std;

int main()
{
	int a, ans = 0;
	for(cin >> a; a; a /= 10) ans += a % 10;
	cout << ans << endl;
	return 0;
}
