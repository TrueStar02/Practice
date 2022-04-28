#include<iostream>
#include<cstdlib>
using namespace std;
double hmean(double a,double b);
int main()
{	double x,y,z;
	cout<<"Enter two numbers:";
	while(cin>>x>>y)
	{	z=hmean(x,y);
		cout<<"Result:"<<z<<endl;
		cout<<"Enter two numbers:";
	}
	cout<<"Bye~\n";
	return 0;
}
double hmean(double a,double b)
{	double z;
	if(a+b==0)
	{	cout<<"Invalid Input!\n";
		abort();
	}
	else
	{	z=2.0*a*b/(a+b);
		return z;
	}
}
