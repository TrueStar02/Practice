#include<iostream>
using namespace std;
typedef pair<int,int> Player;
int main()
{   int x,y,pos,w;
    cin>>pos>>w;
    int count[pos+1];
    count[0]=0;
    for(x=0;x<pos;x++)
    {   cin>>count[x+1];
            count[x+1]+=count[x];
    }
    int tot=count[pos];
    count[0]=0;
    Player arr[tot];
    for(x=0;x<count[pos];x++)
        cin>>arr[x].first>>arr[x].second;
    int dp[tot][w+1],prev[tot][w+1];
    int i=0;
    for(y=0;y<=w;y++)
    {   if(y<arr[0].first)
            dp[0][y]=0;
        else
            dp[0][y]=arr[0].second;
        prev[0][y]=-1;
    }
    
    for(x=0;x<tot;x++)
    {   dp[x][0]=0;
        prev[x][0]=-1;
    }       
    int cur;
    for(y=1;y<=w;y++)
    {   if(dp[0][y]==0)
            cur=-1;
        else
            cur=0;
        i=0;
        for(x=1;x<tot;x++)
        {   if(x>=count[i])
                i++;
            if(cur<count[i-1])
            {   if(arr[x].first<=y&&arr[x].second+dp[x-1][y-arr[x].first]>dp[x-1][y])
                {   dp[x][y]=arr[x].second+dp[x-1][y-arr[x].first];
                    prev[x][y]=cur;
                    cur=x;
                }
                else
                {   dp[x][y]=dp[x-1][y];
                    prev[x][y]=cur;
                }

            }
            else
            {   if(arr[x].first<=y&&dp[cur][y]<(cur>0?(dp[cur-1][y-arr[x].first]):0)+arr[x].second)
                {   dp[x][y]=(cur>0?(dp[cur-1][y-arr[x].first]):0)+arr[x].second;
                    //prev[x][y]=cur;
                    cur=x;
                }
                else
                {   dp[x][y]=dp[cur][y];   
                    prev[x][y]=cur;
                }
            }
            
        }     
        

    }
    for(x=0;x<tot;x++)
    {   for(y=0;y<=w;y++)
            cout<<dp[x][y]<<" ";
        cout<<endl;
    } 
     cout<<dp[tot-1][w]<<endl;


}