#include<iostream>
using namespace std;
int main()
{	int n,x;
	cin>>n;
	int count=0;
	int a[n];
	for(x=0;x<n;x++)
	cin>>a[x];
	if(n==2)
	{	
		for(x=1;x<=a[1]/2;x++)
			if(a[1]%x==0)count++;
	}
	cout<<count;
}