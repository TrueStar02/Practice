#include<iostream>
#include<vector>
using namespace std;
int main()
{	vector<int> pos[10001];
	int x,y,n,max=0,count=0,maxcount;
	cin>>n;
	int a[n+2];
	a[0]=0;
	a[n+1]=0;
	for(x=1;x<=n;x++)
	{	cin>>a[x];
		if(a[x])
		{
			pos[a[x]].push_back(x);
			if(!a[x-1])
				count++;
		}
		if(a[x]>max)
			max=a[x];
	}
	maxcount=count;
	for(x=1;x<=max;x++)
	{
		for(y=0;y<pos[x].size();y++)
		{	a[pos[x][y]]=0;
			if(a[pos[x][y]-1]==0&&a[pos[x][y]+1]==0)
				count--;
			else if(a[pos[x][y]-1]&&a[pos[x][y]+1])
				count++;
		}
		if(maxcount<count)
			maxcount=count;
			
	}
	cout<<maxcount;
	return 0;
}