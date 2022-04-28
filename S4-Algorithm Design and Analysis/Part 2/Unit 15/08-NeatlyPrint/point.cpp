#include<iostream>
using namespace std;
const int inf=1e9;
int main()
{   int n,x,y,max_len,temp;
    cin>>n>>max_len;
    int len[n];
    for(x=0;x<n;x++)
        cin>>len[x];
    int tot_len[n][n];
    int cubic[n][n];
    for(x=0;x<n;x++)
    {   tot_len[x][x]=len[x];
        for(y=x+1;y<n;y++)
            tot_len[x][y]=tot_len[x][y-1]+1+len[y];
    }
    for(x=0;x<n;x++)
    for(y=x;y<n;y++)
    {   temp=max_len-tot_len[x][y];
        if(temp>=0)
            cubic[x][y]=temp*temp*temp;
        else
            cubic[x][y]=inf;

    }
    int arr[n+1];
    int *dp=arr+1;
    dp[-1]=0;
    for(x=0;x<n;x++)
    {   temp=inf;
        for(y=-1;y<x;y++)
        {   if(temp>dp[y]+cubic[y+1][x])
                temp=dp[y]+cubic[y+1][x];

        }
        dp[x]=temp;

    }
    for(y=n-1;y>=0;y--)
    {   if(dp[y]<dp[y+1])
            break;

    }
    cout<<dp[y]<<endl;
    return 0;
    

}