#include<iostream>
#include<stack>
using namespace std;
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str1;
    cin>>str1;
    int x,y;
    string str2(str1.rbegin(),str1.rend());

    int len1=str1.length(),len2=str2.length();
    int dp[len1+1][len2+1];
    
    for(x=0;x<=len1;x++)
        dp[x][0]=0;
    for(x=0;x<=len2;x++)
        dp[0][x]=0;
    for(x=1;x<=len1;x++)
    for(y=1;y<=len2;y++)
    {   if(str1[x-1]==str2[y-1])
            dp[x][y]=dp[x-1][y-1]+1;
        else if(dp[x-1][y]>dp[x][y-1])
            dp[x][y]=dp[x-1][y];
        else
            dp[x][y]=dp[x][y-1];
    }
    cout<<dp[len1][len2]<<'\n';
    stack<char> st;
    x=len1;
    y=len2;
    while(x&&y)
    {   if(str1[x-1]==str2[y-1])
        {   st.push(str1[x-1]);
            x--;
            y--;
        }
        else if(dp[x][y]==dp[x-1][y])
            x--;
        else
            y--;
    }
    while(st.size())
    {   cout.put(st.top());
        st.pop();
    }
    cout.put('\n');
    return 0;
}