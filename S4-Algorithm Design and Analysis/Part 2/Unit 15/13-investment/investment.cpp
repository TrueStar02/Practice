#include<iostream>
#include<stack>
using namespace std;
int main()
{   int x,y,years,ideas;
    double f1,f2,ori;
    cin>>years>>ideas>>ori>>f1>>f2;
    double dp[years][ideas],rate[years][ideas],pre[years][ideas];
    int choice[years];
    for(x=0;x<years;x++)
    for(y=0;y<ideas;y++)
        cin>>rate[x][y];
    int index=-1;
    double max=0;
    for(y=0;y<ideas;y++)
    {   dp[0][y]=ori*rate[0][y];
        pre[0][y]=-1;
        if(dp[0][y]>max)
        {   max=dp[0][y];
            index=y;
        }
    }
    for(x=1;x<years;x++)
    {   for(y=0;y<ideas;y++)
        {   if(y==index)
            {   dp[x][y]=dp[x-1][y]*rate[x][y]-f1;
                pre[x][y]=y;
            }
            else
            {   if(dp[x-1][y]*rate[x][y]-f1>dp[x-1][index]*rate[x][y]-f2)
                {   dp[x][y]=dp[x-1][y]*rate[x][y]-f1;
                    pre[x][y]=y;
                }
                else
                {   dp[x][y]=dp[x-1][index]*rate[x][y]-f2;
                    pre[x][y]=index;
                }
            }
        }
        index=-1;
        max=0;
        for(y=0;y<ideas;y++)
        {   if(dp[x][y]>max)
            {   max=dp[x][y];
                index=y;
            }
        }
    }
    /*for(x=0;x<years;x++)
    {   for(y=0;y<ideas;y++)
            cout<<dp[x][y]<<" ";
        cout<<endl;
    }*/
    cout<<max<<endl;
    stack<int> st;
    for(x=years-1,y=index;x>=0;y=pre[x][y],x--)
        st.push(y);
    while(st.size())
    {   cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}