#include<iostream>
#include<stack>
#include<cassert>
using namespace std;
const char * ops[6]={"Copy","Replace","Delete","Insert","Twiddle","Kill"};
const int inf=1e9;
int main()
{   int x,y,z;
    int cost[6];//0-copy 1-replace 2-delete 3-insert 4-twiddle 5-kill;
    for(x=0;x<6;x++)
        cin>>cost[x];
    string source,target;
    cin>>source>>target;
    bool kill=0;
    int len1=source.length();
    int len2=target.length();
    assert(len1&&len2);
    int dp[len1+1][len2+1];
    int op[len1+1][len2+1];
    dp[0][0]=0;
    int cur[6];
    int flag,min;
    for(x=1;x<=len2;x++)
    {   dp[0][x]=dp[0][x-1]+cost[3];
        op[0][x]=3;
    }    
    for(x=1;x<=len1;x++)
    {   dp[x][0]=dp[x-1][0]+cost[2];
        op[x][0]=2;
    }
    
    for(x=1;x<=len1;x++)
    for(y=1;y<len2;y++)
    {   for(z=0;z<=4;z++)
            cur[z]=inf;
        if(source[x-1]==target[y-1])
            cur[0]=cost[0]+dp[x-1][y-1];
        else
            cur[1]=cost[1]+dp[x-1][y-1];
        cur[2]=cost[2]+dp[x-1][y];
        cur[3]=cost[3]+dp[x][y-1];
        if(x>1&&y>1&&source[x-1]==target[y-2]&&source[x-2]==target[y-1])
            cur[4]=cost[4]+dp[x-2][y-2];
        min=inf;
        flag=-1;
        for(z=0;z<=4;z++)
            if(min>cur[z])
            {   min=cur[z];
                flag=z;
            }
        dp[x][y]=cur[flag];
        op[x][y]=flag;
    }
    for(x=1;x<=len1;x++)
    {   if(kill)
        {   dp[x][len2]=dp[x-1][len2];
            op[x][len2]=-1;
        }
        else
        {   for(z=0;z<=5;z++)
                cur[z]=inf;
            if(source[x-1]==target[len2-1])
                cur[0]=cost[0]+dp[x-1][len2-1];
            else
                cur[1]=cost[1]+dp[x-1][len2-1];
            cur[2]=cost[2]+dp[x-1][len2];
            cur[3]=cost[3]+dp[x][len2-1];
            if(x>1&&y>1&&source[x-1]==target[len2-2]&&source[x-2]==target[len2-1])
                cur[4]=cost[4]+dp[x-2][len2-2];
            cur[5]=dp[x-1][len2]+cost[5];
            min=inf;
            flag=-1;
            for(z=0;z<=5;z++)
                if(min>cur[z])
                {   min=cur[z];
                    flag=z;
                }
            dp[x][len2]=cur[flag];
            op[x][len2]=flag;
            if(flag==5)
                kill=1;
        }
    }
    cout<<dp[len1][len2]<<endl;
    stack<int> op_stack;
    x=len1;
    y=len2;
    while(x||y)
    {   
        while(op[x][y]==-1)
            x--;
        op_stack.push(op[x][y]);
        switch(op[x][y])
        {   case 0:
            case 1:x--;y--;break;
            case 2:
            case 5:x--;break;
            case 3:y--;break;
            case 4:x=-2;y-=2;break;
        }


    }
    while(op_stack.size())
    {   flag=op_stack.top();
        op_stack.pop();
        cout<<ops[flag]<<endl;
    }
    return 0;

}