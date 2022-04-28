#include<iostream>
using namespace std;
template <typename T>
void Swap(T &a,T &b);
int main()
{	int a=10,b=20;
	double da=1.2,db=2.1;
	char ca='a',cb='b';
	Swap(a,b);
	swap(da,db);
	Swap(ca,cb);
	cout<<a<<" "<<b<<endl;
	cout<<da<<" "<<db<<endl;
	cout<<ca<<" "<<cb<<endl;
	return 0;
}
template <typename T>
void Swap(T &a,T &b)
{	T temp;
	temp=a;
	a=b;
	b=temp;
}
