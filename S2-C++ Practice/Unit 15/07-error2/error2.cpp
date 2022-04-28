#include<iostream>
#include<cstdlib>
using namespace std;
bool hmean(double a,double b,double * result);
int main()
{	double x,y,z;
	cout<<"Enter two numbers:";
	while(cin>>x>>y)
	{	if(hmean(x,y,&z))
		{	cout<<"Result:"<<z<<endl;
			cout<<"Enter two numbers:";
		}
		else
			cout<<"Try again:";
	}
	cout<<"Bye~\n";
	return 0;
}
bool hmean(double a,double b,double * result)
{	if(a+b==0)
	{	cout<<"Invalid Input!\n";
		return 0;
	}
	else
	{	*result=2.0*a*b/(a+b);
		return 1;
	}
}
