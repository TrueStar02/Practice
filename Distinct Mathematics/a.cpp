#include<iostream>
using namespace std;
long long comb(int m,int n)
{   long long i=1;
	int x;
    for(x=n;x>=n-m+1;x--)
        i*=x;
    for(x=1;x<=m;x++)
        i/=x;
    return i;
}
int main()
{   int n,x,y;
    cin>>n;
    long long a[n+1];
    a[0]=a[1]=1;
    for(x=2;x<=n;x++)
        a[x]=0;
    for(x=2;x<=n;x++)
    for(y=0;y<=x-1;y++)
        a[x]+=comb(y,x-1)*a[y];
    cout<<a[n];
}
