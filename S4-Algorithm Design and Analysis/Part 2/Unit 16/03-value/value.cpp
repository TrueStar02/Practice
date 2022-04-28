#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Course
{   int first;
    int second;
    int value;
};
struct comp
{
    bool operator()(const Course & c1,const Course & c2){return c1.second<c2.second;}
};
int main()
{   int x,n;
    cin>>n;
    Course arr[n];
    for(x=0;x<n;x++)
        cin>>arr[x].first>>arr[x].second>>arr[x].value;
    sort(arr,arr+n,comp());
    bool selected[n];
    int prior[n],dp[n];
    selected[0]=1;
    dp[0]=arr[0].value;
    prior[0]=-1;
    //for(x=1;x<n;x++)
    //    selected[x]=0;
    int beg,mid,end;
    for(x=1;x<n;x++)
    {   beg=0;
        end=x-1;
        while(beg<=end)
        {   mid=(beg+end)/2;
            if(arr[mid].second>arr[x].first)
                end=mid-1;
            else if(arr[mid].second<arr[x].first)
                beg=mid+1;
            else
            {   end=mid;
                break;
            }
        }
        if(end>=0&&dp[end]+arr[x].value>dp[x-1])
        {   selected[x]=1;
            dp[x]=dp[end]+arr[x].value;
            prior[x]=end;
        }
        else
        {   selected[x]=0;
            dp[x]=dp[x-1];
            prior[x]=x-1;            
        }
        
    }
    cout<<dp[n-1]<<endl;
    x=n-1;
    while(x>=0)
    {   if(selected[x]==1)
            cout<<x<<" ";
        x=prior[x];
    }
    /*for(x=0;x<n;x++)
        cout<<dp[x]<<" ";*/
    cout<<endl;
    return 0;
}
