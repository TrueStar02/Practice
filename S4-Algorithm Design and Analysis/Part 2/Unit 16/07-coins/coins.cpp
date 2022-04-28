#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int x,y,n,k;
    cin>>n>>k;
    int dp[k][n+1];
    bool op[k][n+1];
    int type[k];
    for(x=0;x<k;x++)
    {   cin>>type[x];
        dp[x][0]=0;
        op[x][0]=0;
    }
    sort(type,type+k);
    for(x=1;x<=n;x++)
    {   dp[0][x]=x;
        op[0][x]=1;
    }
    for(x=1;x<k;x++)
    for(y=1;y<=n;y++)
    {   if(y>=type[x]&&dp[x][y-type[x]]+1<dp[x-1][y])       
        {   op[x][y]=1;
            dp[x][y]=dp[x][y-type[x]]+1;
        }    
        else
        {   op[x][y]=0;
            dp[x][y]=dp[x-1][y];
        }    
    }
    cout<<dp[k-1][n]<<endl;
    for(x=k-1,y=n;y>0;)
    {   if(op[x][y])
        {   cout<<type[x]<<" ";
            y-=type[x];
        }
        else
            x--;
    }
    cout<<endl;
    return 0;
}