#include<iostream>
#include<stack>
using namespace std;
const int inf=1e9;
typedef pair<int,int> Interval;
int main()
{   int n,tot,x,y,z,brk,min,res;
    cin>>n>>tot;
    int len[n+1];
    for(x=0;x<n;x++)
        cin>>len[x];
    len[n]=tot-1;
    for(x=n;x>0;x--)
        len[x]=len[x]-len[x-1];
    len[0]++;
    int dp[n+1][n+1],cut[n+1][n+1],tot_len[n+1][n+1];
    for(x=0;x<=n;x++)
    {   dp[x][x]=0;
        tot_len[x][x]=len[x];
        for(y=x+1;y<=n;y++)
            tot_len[x][y]=tot_len[x][y-1]+len[y];
    }
    for(x=2;x<=n+1;x++)
    {   for(y=0;y<=n+2-x;y++)
        {   min=inf;
            for(z=y;z<x+y-1;z++)
            {   res=dp[y][z]+dp[1+z][x+y-1]+tot_len[y][x+y-1];
                if(res<min)
                {   min=res;
                    brk=z;
                }
                dp[y][x+y-1]=min;
                cut[y][x+y-1]=brk;
            }

        }

    }
    cout<<dp[0][n]<<endl;
    stack<Interval> st;
    Interval temp;
    st.push(Interval(0,n));
    while(st.size())
    {   temp=st.top();
        st.pop();
        cout<<cut[temp.first][temp.second]<<" ";
        if(temp.first!=cut[temp.first][temp.second])
            st.push(Interval(temp.first,cut[temp.first][temp.second]));
        if(temp.second!=cut[temp.first][temp.second]+1)
            st.push(Interval(cut[temp.first][temp.second]+1,temp.second));
    }
    return 0;
}