#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y,n,max,val,pi;
    cin>>n;
    int arr[n],add[n];
    for(x=0;x<n;x++)
    {   cin>>arr[x];
        add[x]=arr[x];
    }
    sort(add,add+n);
    int dp[n+1][n+1];
    for(x=0;x<=n;x++)
        dp[x][0]=0;
    for(x=0;x<=n;x++)
        dp[0][x]=0;
    for(x=1;x<=n;x++)
    for(y=1;y<=n;y++)
    {   if(arr[x-1]==add[y-1])
            dp[x][y]=dp[x-1][y-1]+1;
        else if(dp[x-1][y]>dp[x][y-1])
            dp[x][y]=dp[x-1][y];
        else
            dp[x][y]=dp[x][y-1];
    }
    cout<<dp[n][n]<<'\n';
    stack<int> st;
    x=n;
    y=n;
    while(x&&y)
    {   if(arr[x-1]==add[y-1])
        {   st.push(arr[x-1]);
            x--;
            y--;
        }
        else if(dp[x][y]==dp[x-1][y])
            x--;
        else
            y--;
    }
    while(st.size())
    {   cout<<st.top()<<" ";
        st.pop();
    }
    cout.put('\n');
    return 0;


}