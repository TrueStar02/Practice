#include<iostream>
using namespace std;
double hmean(double a,double b);
int main()
{	double x,y,z;
	cout<<"Enter two numbers:";
	while(cin>>x>>y)
	{	try{z=hmean(x,y);}
		catch(const char * s)
		{	cout<<s<<endl;
			cout<<"Try again:";
			continue;
		}
		cout<<"Result:"<<z<<endl;
		cout<<"Enter two numbers:";
	}
	cout<<"Bye~\n";
	return 0;
}
double hmean(double a,double b)
{	double z;
	if(a+b==0)
		throw "Invalid Input!";
	z=2.0*a*b/(a+b);
	return z;
}
