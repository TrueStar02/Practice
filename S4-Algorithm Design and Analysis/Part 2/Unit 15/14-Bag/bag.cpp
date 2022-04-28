#include<iostream>
using namespace std;
typedef pair<int,int> Thing;
int main()
{   int n,w,x,y;
    cin>>n>>w;
    int dp[n][w+1];
    Thing things[n];
    for(x=0;x<n;x++)
    {   cin>>things[x].first>>things[x].second;
        dp[x][0]=0;
    }
    for(y=1;y<w;y++)
    {   if(things[0].first<=y)
            dp[0][y]=things[0].second;
        else
            dp[0][y]=0;
    }
    for(x=1;x<n;x++)
    for(y=1;y<=w;y++)
    {   if(y>=things[x].first&&dp[x][w-1]<things[x].second+dp[x-1][w-things[x].first])
            dp[x][y]=things[x].second+dp[x-1][w-things[x].first];
        else
            dp[x][y]=dp[x-1][w];
    }
    cout<<dp[n-1][w]<<endl;
    return 0;
}