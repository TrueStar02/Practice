#include<iostream>
#include<stack>
using namespace std;
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y,z,n;
    cin>>n;
    double node[n+1],delta[n+1];
    for(x=1;x<=n;x++)
        cin>>node[x];
    for(x=0;x<=n;x++)
        cin>>delta[x];
    double dp[n+1][n+1];
    double tot[n+1][n+1];
    int brk[n+1][n+1];
    for(x=1;x<=n;x++)
    {   tot[x][x]=delta[x-1]+node[x]+delta[x];
        dp[x][x]=tot[x][x]+delta[x-1]+delta[x];
        brk[x][x]=x;
    }
    double min,res,cur_tot;
    for(x=2;x<=n;x++)
    {   for(y=1;y<=n-x+1;y++)
        {   min=999999999;
            for(z=brk[y][y+x-2];z<=brk[y+1][y+x-1];z++)
            {   if(z==y)
                {   cur_tot=node[z]+delta[z-1]+tot[y+1][y+x-1];
                    res=dp[y+1][y+x-1]+tot[y+1][y+x-1]+2*delta[y-1]+node[z];
                }
                else if(z==y+x-1)
                {   cur_tot=node[z]+delta[z]+tot[y][z-1];
                    res=dp[y][z-1]+tot[y][z-1]+2*delta[z]+node[z];
                }
                else
                {   cur_tot=node[z]+tot[y][z-1]+tot[z+1][y+x-1];
                    res=node[z]+tot[y][z-1]+tot[z+1][y+x-1]+dp[y][z-1]+dp[z+1][y+x-1];
                }
                if(min>res)
                {   dp[y][x+y-1]=res;
                    tot[y][x+y-1]=cur_tot;
                    brk[y][x+y-1]=z;
                    min=res;
                }

            }

        }
    } 
    cout<<dp[1][n]<<'\n';
    typedef pair<int,int> Interval;
    stack<Interval> st;
    st.push(Interval(1,n));
    Interval temp;
    while(st.size())
    {   temp=st.top();
        st.pop();
        if(temp.first<temp.second)
        {   cout<<brk[temp.first][temp.second]<<" ";
            st.push(Interval(temp.first,brk[temp.first][temp.second]-1));
            st.push(Interval(brk[temp.first][temp.second]+1,temp.second));
        }
    }
    cout<<'\n';
    return 0;


}
