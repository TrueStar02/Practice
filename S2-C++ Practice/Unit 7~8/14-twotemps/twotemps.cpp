#include<iostream>
using namespace std;
template <typename T>
void Swap(T &a,T &b);
template <typename T>
void Swap(T *a,T *b,int n);
int main(void)
{	int a=10,b=20,x;
	double da[5]={1.1,2.2,3.3,4.4,5.5};
	double db[5]={1.5,2.4,3.3,4.2,5.1};
	Swap(a,b);
	Swap(da,db,5);
	cout<<a<<" "<<b<<endl;
	for(x=0;x<5;x++)
		cout<<da[x]<<" "<<db[x]<<endl;
	return 0;
}
template <typename T>
void Swap(T &a,T &b)
{	T temp;
	temp=a;
	a=b;
	b=temp;
}
template <typename T>
void Swap(T *a,T *b,int n)
{	T temp;
	int x;
	for(x=0;x<n;x++)
	{	temp=a[x];
		a[x]=b[x];
		b[x]=temp;
	}
}
