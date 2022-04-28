#include "error.h"
#include<cmath>
double hmean(double a,double b);
double gmean(double a,double b);
int main()
{	double x,y,z;
	cout<<"Enter two numbers:";
	while(cin>>x>>y)
	{	try
		{	z=hmean(x,y);
			cout<<"Result of harmonic mean:"<<z<<endl;
			cout<<"Result of geometric mean:"<<gmean(x,y)<<endl;
			cout<<"Enter two numbers:";
		}
		catch(bad_hmean & bh)
		{	cout<<bh.what();
			cout<<"Try again:";
			continue;
		}
		catch(bad_gmean & bg)
		{	cout<<bg.what();
			cout<<"SB!\n";
			break;
		}
	}
	cout<<"Bye~\n";
	return 0;
}
double hmean(double a,double b)
{	double z;
	if(a+b==0)
	{	cout<<"Invalid Input!\n";
		throw bad_hmean();
	}
	else
	{	z=2.0*a*b/(a+b);
		return z;
	}
}
double gmean(double a,double b)
{	if(a<0||b<0)
	{	cout<<"Invalid Input!\n";
		throw bad_gmean();
	}
	else
		return sqrt(a*b);
}

