#include<iostream>
using namespace std;
struct job
{	string name;
	string job;
};
template <typename T>
void Swap(T &a,T &b);
template <typename T>
void Swap(T *a,T *b,int n);
template <> void Swap<job>(job & a,job & b);
int main(void)
{	int a=10,b=20,x;
	double da[5]={1.1,2.2,3.3,4.4,5.5};
	double db[5]={1.5,2.4,3.3,4.2,5.1};
	job ja={"Trump","President"},jb={"Biden","Not President"};
	Swap(a,b);
	Swap(da,db,5);
	Swap(ja,jb);
	cout<<a<<" "<<b<<endl;
	for(x=0;x<5;x++)
		cout<<da[x]<<" "<<db[x]<<endl;
	cout<<ja.name<<" "<<ja.job<<endl;
	cout<<jb.name<<" "<<jb.job<<endl;
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
template <> void Swap<job>(job & a,job & b)
{	string temp;
	temp=a.job;
	a.job=b.job;
	b.job=temp;
}
