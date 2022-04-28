#include<iostream>
using namespace std;
int main()
{	int m,n,l,x,y;
	cin>>m>>n>>l;
	int out[l]={0};
	for(x=0;x<m*n;x++)
	{	cin>>y;
		out[y]++;
	}
	for(x=0;x<l;x++)
		cout<<out[x]<<" ";
	return 0;
}