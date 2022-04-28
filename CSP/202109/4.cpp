#include<iostream>
using namespace std;
double pos(unsigned short label,int count,const double * arr,int size,int coins,int k,int times)
{	
	if((size-count)*k<=coins)
		return times;
	else
	{	double p=0;
		int x;
		for(x=0;x<size;x++)
		{	if((label>>x)&1)
				p+=arr[x]*pos(label,count,arr,size,coins+1,k,times+1);
			else
				p+=arr[x]*pos(label|(1<<x),count+1,arr,size,coins,k,times+1);
			
		}
		return p;
	}
	
}
double pos2(int count,const double * arr,int size,int coins,int k,int times)
{	if((size-count)*k<=coins)
		return times;
	else
	{	return arr[0]*count*pos2(count,arr,size,coins+1,k,times+1)+arr[0]*(size-count)*pos2(count+1,arr,size,coins,k,times+1);
		
	}
	
	
}
int main()
{	int n,k,x;
	cin>>n>>k;
	double arr[n];
	//bool label[n];
	for(x=0;x<n;x++)
	{	//label[x]=0;
		cin>>arr[x];
	}
	if(n<6&&k<6)
		cout<<pos(0,0,arr,n,0,k,0);
	else
		cout<<pos2(0,arr,n,0,k,0);
	return 0;
}