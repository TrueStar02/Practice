#include<iostream>
#include<cstring>
#include "sales.h"
using namespace std;
static void calc(SALES::Sales &s,int n);
namespace SALES
{	void setSales(Sales& s, const double ar[], int n)
    {	if(n>4)
    		n=4;
    	memcpy(s.sales,ar,n*sizeof(double));
    	calc(s,n);
    }
    void setSales(Sales& s)
    {	int n=0;
    	while(n<4)
    	{	cout<<"Enter the detail,-1 to quit:";
    		while(!(cin>>s.sales[n]))
    		{	cin.clear();
    			while(cin.get()!='\n')
    				continue;
    			cout<<"Enter a number!:";
    		}
    		if(s.sales[n]==-1)
    		{	cout<<"Quit!"<<endl;
    			break;
    		}
    		else
    			n++;
    	}
    	calc(s,n);
    }
    void showSales(const Sales& s)
    {	cout<<"AVE:"<<s.average<<" MAX:"<<s.max<<" MIN:"<<s.min<<endl;
    }
}
static void calc(SALES::Sales &s,int n)
{	s.average=s.sales[0];
	s.min=s.sales[0];
	s.max=s.sales[0];
	int x;
	for(x=1;x<n;x++)
	{	s.average+=s.sales[x];
		if(s.sales[x]>s.max)
			s.max=s.sales[x];
		else if(s.sales[x]<s.min)
			s.min=s.sales[x];
	}
	s.average/=n;
}
