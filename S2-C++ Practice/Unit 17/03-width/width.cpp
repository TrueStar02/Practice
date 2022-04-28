#include<iostream>
using namespace std;
int main()
{	cout<<" x  x*x\n";
	int x;
	for(x=1;x<100;x++)
	{	cout.width(2);
		cout<<x;
		cout.width(5);
		cout<<x*x<<endl;
	}
	return 0;
}
