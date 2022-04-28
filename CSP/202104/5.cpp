#include<iostream>
using namespace std;
int main()
{	int n,x,r;
	cin>>n>>r;
	int count=0;
	int t[n+1];
	for(x=1;x<=n;x++)
	t[x]=-1;
	int sum=0,m;
	cin>>m;
	int a,b;
	for(x=1;x<=m;x++)
	{	cin>>a>>b;
		sum+=b;
		t[a]=sum;
	}
	for(x=2;x<=n;x++)
	{	if(t[x]==-1)
			cout<<"inf\n";
		else
			cout<<t[x]<<endl;
	}
}