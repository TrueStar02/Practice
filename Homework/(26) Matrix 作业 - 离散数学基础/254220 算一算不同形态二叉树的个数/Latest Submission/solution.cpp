#include<iostream>
using namespace std;
int main()
{   int n,x,y;
    cin>>n;
    if(n==0)
    {   cout<<"1";
        return 0;
    }
    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    for(x=2;x<=n;x++)
    {   arr[x]=0;
        for(y=0;y<=x-1;y++)
            arr[x]+=arr[y]*arr[x-1-y];
    }
    cout<<arr[n];
    return 0;
}   