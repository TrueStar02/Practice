#include<iostream>
#include<stack>
using namespace std;
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y,z,n,min,res,pre;
    cin>>n;
    int size[n+1],dp[n+1][n+1],mem[n+1][n+1];
    for(x=0;x<=n;x++)
        cin>>size[x];
    for(x=1;x<=n;x++)
    {   dp[x][x]=0;
        mem[x][x]=0;
    }
    for(z=2;z<=n;z++)
    {   for(x=1;x<=n-z+1;x++)
        {   min=999999999;
            pre=0;
            for(y=x;y<x+z-1;y++)
            {   res=dp[x][y]+dp[y+1][x+z-1]+size[x-1]*size[y]*size[x+z-1];
                if(min>res)
                {   min=res;
                    pre=y;
                }
                dp[x][x+z-1]=min;
                mem[x][x+z-1]=pre;
            }
        }
    }
    cout<<dp[1][n]<<'\n';
    typedef pair<int,int> Interval;
    stack<Interval> st;
    st.push(Interval(1,n));
    Interval temp;
    int p;
    while(st.size())
    {   temp=st.top();
        st.pop();
        p=mem[temp.first][temp.second];
        cout<<p<<" ";
        if(p!=temp.first)
            st.push(Interval(temp.first,p));
        if(p+1!=temp.second)
            st.push(Interval(p+1,temp.second));
    }
}