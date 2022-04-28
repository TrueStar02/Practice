#include<iostream>
using namespace std;
int main()
{	int n,x;
	cin>>n;
	int m,temp=-1,max=0,min=0;
	for(x=0;x<n;x++)
	{	cin>>m;
		if(temp<m)
		{	temp=m;
			min+=m;
			
		}
		max+=m;
	}
	cout<<max<<endl<<min<<endl;
	return 0;
}