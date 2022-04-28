#include<iostream>
using namespace std;
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x,y,max;
    cin>>n;
    int dp[n>10?n+1:11]={0,1,5,8,10,13,17,18,22,25,30};
    for(x=11;x<=n;x++)
    {   max=0;
        for(y=1;y<=x/2;y++)
            if(dp[y]+dp[x-y]>max)
                max=dp[y]+dp[x-y];
        dp[x]=max;
    }
    cout<<dp[n];
    return 0;

}