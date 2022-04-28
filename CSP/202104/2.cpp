#include<iostream>
using namespace std;
int val(int pos,int size,int r);
int main()
{	int n,l,r,t,x,y,count=0;
	cin>>n>>l>>r>>t;
	int ptr1[n+2*r][n+2*r]={0};
	int ptr2[n+2*r][n+2*r]={0};
	int ptr3[n+2*r][n+2*r]={0};
	for(x=0;x<n+r+r;x++)
	for(y=0;y<n+r+r;y++)
		ptr1[x][y]=ptr2[x][y]=ptr3[x][y]=0;
		
	
	for(x=0+r;x<n+r;x++)
	for(y=0+r;y<n+r;y++)
		cin>>ptr1[x][y];
	for(x=0+r;x<n+r;x++)
	for(y=0+r;y<=r+r;y++)
		ptr2[x][0+r]+=ptr1[x][y];
	
	for(x=0+r;x<n+r;x++)
	for(y=1+r;y<n+r;y++)
		ptr2[x][y]=ptr2[x][y-1]+ptr1[x][y+r]-ptr1[x][y-r-1];
	
	for(y=0+r;y<n+r;y++)
	for(x=0+r;x<=r+r;x++)
		ptr3[0+r][y]+=ptr2[x][y];
	
	for(y=0+r;y<n+r;y++)
	for(x=1+r;x<n+r;x++)
		
		ptr3[x][y]=ptr3[x-1][y]+ptr2[x+r][y]-ptr2[x-r-1][y];
	
	
	for(x=0+r;x<n+r;x++)
	for(y=0+r;y<n+r;y++)
		if(ptr3[x][y]<=val(x-r,n,r)*val(y-r,n,r)*t)
			count++;
	cout<<count;
	return 0;
}
int val(int pos,int size,int r)
{	int v=1;
	if(pos<r) v+=pos;
	else v+=r;
	if(size-pos-1<r) v+=size-pos-1;
	else v+=r;
	return v;
}