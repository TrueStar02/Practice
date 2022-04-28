#include<iostream>
#include<stack>
using namespace std;
const int inf=1e9;
int main()
{   int n,m,c;
    cin>>n>>m>>c;
    int x,y,z,s,tot[n+1],min,res,num;
    tot[0]=0;
    for(x=1;x<=n;x++)
    {   cin>>tot[x];
        tot[x]+=tot[x-1];
    }
    int h[tot[n]];
    h[0]=0;
    for(x=1;x<tot[n];x++)
        cin>>h[x];
    int dp[n+1][tot[n]];
    int cur[n+1][tot[n]];
    for(x=tot[1];x<=tot[n];x++)
    {   dp[1][x]=h[x-tot[1]];
        if(x>m)
            dp[1][x]+=c*(x-m);
        cur[1][x]=x;
    } 
    for(x=2;x<=n;x++)
    {   for(y=tot[x];y<=tot[n];y++)
        {   min=inf;
            for(z=tot[x-1];z<=y;z++)
            {   res=dp[x-1][z];
                if(y-z>m)
                    res+=(y-z-m)*c;
                if(y>tot[x])
                    res+=h[y-tot[x]];
                if(res<min)
                {   min=res;
                    num=y-z;
                }
            }
            dp[x][y]=min;
            cur[x][y]=num;
        }

    }  
    stack<int> st;
    cout<<dp[n][tot[n]]<<endl;
    for(x=n,y=tot[n];x>=1;x--)
    {   st.push(cur[x][y]);
        y-=cur[x][y];
    }
    while(st.size())
    {   cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}