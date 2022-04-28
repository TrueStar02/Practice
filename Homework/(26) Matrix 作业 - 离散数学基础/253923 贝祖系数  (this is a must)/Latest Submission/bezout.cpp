#include<iostream>
using namespace std;
pair<int,int> bezout(int m, int n)
{   int temp;
	bool rev=0;
    if(m<n)
    {   temp=m;
        m=n;
        n=temp;
        rev=1;
    }
    if(n==0)
	{	if(rev==0)
		   	   return pair<int,int>(1,0);
		else
			return pair<int,int>(0,1);
    }
    else
    {    pair<int,int> r=bezout(n,m%n);
    	if(rev==0)
        	return pair<int,int> (r.second,r.first-(m/n)*r.second);
        else
        	return pair<int,int> (r.first-(m/n)*r.second,r.second);
    }
}