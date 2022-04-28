#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int,int> Point;
struct comp
{
    bool operator()(Point a,Point b){return a.first<b.first;}
};
int main()
{   int x,y,n;
    cin>>n;
    Point arr[n];
    double dp[n][n];
    for(x=0;x<n;x++)
        cin>>arr[x].first>>arr[x].second;
    sort(arr,arr+n,comp());
    dp[0][0]=0;
    dp[0][1]=sqrt((arr[0].first-arr[1].first)*(arr[0].first-arr[1].first)+(arr[0].second-arr[1].second)*(arr[0].second-arr[1].second));
    double min,res;
    for(x=0;x<n;x++)
    {   if(x)
        {   min=999999999;
            for(y=0;y<x;y++)
            {   res=dp[y][x]+sqrt((arr[y].first-arr[x].first)*(arr[y].first-arr[x].first)+(arr[y].second-arr[x].second)*(arr[y].second-arr[x].second));
                if(res<min)
                    min=res;
            }
            dp[x][x]=min;
        }
        if(x&&x!=n-1)
        {   min=999999999;
            for(y=0;y<x;y++)
            {   res=dp[y][x]+sqrt((arr[y].first-arr[x+1].first)*(arr[y].first-arr[x+1].first)+(arr[y].second-arr[x+1].second)*(arr[y].second-arr[x+1].second));
                if(res<min)
                    min=res;
            }
            dp[x][x+1]=min;
        }
        for(y=x+2;y<n;y++)
            dp[x][y]=dp[x][y-1]+sqrt((arr[y-1].first-arr[y].first)*(arr[y-1].first-arr[y].first)+(arr[y-1].second-arr[y].second)*(arr[y-1].second-arr[y].second));

    }
    for(x=0;x<n;x++)
    {   for(y=0;y<n;y++)
            if(x<=y)
                cout<<dp[x][y]<<" ";
            else
                cout<<0.0<<" ";
        cout<<endl;
    }
    return 0;
}