#include<iostream>
using namespace std;
inline double func(double x){return x*x+x;}
int main(void)
{	double x;
	cin>>x;
	cout<<func(x);
	return 0;
}
