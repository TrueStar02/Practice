#include<iostream>
using namespace std;
int Choice(int a,int b);
template <typename T>
T Choice(T a,T b);
int main(void)
{	int a=6,b=10;
	double da=1.2,db=3.4;
	cout<<Choice(a,b)<<endl;
	cout<<Choice(da,db)<<endl;
	cout<<Choice<>(a,b)<<endl;
	cout<<Choice<int>(a,b)<<endl;
	return 0;
}
int Choice(int a,int b)
{	if(a>b)
		return b;
	return a;
}
template <typename T>
T Choice(T a,T b)
{	if(a<b)
		return b;
	return a;
}
