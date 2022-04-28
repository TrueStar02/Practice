#include<iostream>
using namespace std;
int main()
{   int m,n,x,y;
    cin>>m>>n;
    int graph[m][n];
    int dp[m][n];
    int dir[m][n];
    for(x=0;x<m;x++)
    for(y=0;y<n;y++)
            cin>>graph[x][y];
    for(y=0;y<n;y++)
    {   dp[0][y]=graph[0][y];
        dir[0][y]=0;
    }
    for(x=1;x<m;x++)
    {   if(dp[x-1][0]>dp[x-1][1])
        {   dp[x][0]=graph[x][0]+dp[x-1][1];
            dir[x][0]=-1;
        }
        else
        {   dp[x][0]=graph[x][0]+dp[x-1][0];
            dir[x][0]=0;
        }
        for(y=1;y<n-1;y++)
        {   if(dp[x-1][y]<dp[x-1][y-1]&&dp[x-1][y]<dp[x-1][y+1])
            {   dp[x][y]=graph[x][y]+dp[x-1][y];
                dir[x][y]=0;
            }
            else if(dp[x-1][y-1]<dp[x-1][y+1])
            {   dp[x][y]=graph[x][y]+dp[x-1][y-1];
                dir[x][y]=1;
            }
            else
            {   dp[x][y]=graph[x][y]+dp[x-1][y+1];
                dir[x][y]=-1;
            }
            

        }
        if(dp[x-1][n-2]>dp[x-1][n-1])
        {   dp[x][n-1]=graph[x][n-1]+dp[x-1][n-1];
            dir[x][n-1]=0;
        }
        else
        {   dp[x][n-1]=graph[x][n-1]+dp[x-1][n-2];
            dir[x][n-1]=1;
        }
    }
    int min=1e9,index=-1;
    for(y=0;y<n;y++)
    {   if(dp[m-1][y]<min)
        {   min=dp[m-1][y];
            index=y;
        }
    }
    cout<<dp[m-1][index]<<endl;
    for(x=m-1,y=index;x>=0;y-=dir[x][y],x--)
        cout<<'('<<x<<','<<y<<") ";
    cout<<endl;
    return 0;
}