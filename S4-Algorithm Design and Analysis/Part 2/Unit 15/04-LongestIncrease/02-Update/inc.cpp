#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y,n,len=1;
    cin>>n;
    int arr[n];
    for(x=0;x<n;x++)
        cin>>arr[x];
    int max[n+1];
    for(x=1;x<=n;x++)
        max[x]=999999999;
    vector<int> seq[n+1];
    seq[1].push_back(999999999);
    for(x=0;x<n;x++)
    {   if(arr[x]<max[1])
        {   max[1]=arr[x];
            seq[1][0]=arr[x];
        }
        else
        {   for(y=0;arr[x]>max[y+1];y++)
                continue;
            max[y+1]=arr[x];
            seq[y+1]=seq[y];
            seq[y+1].push_back(arr[x]);
            if(len<y+1)
                len=y+1;
        }

    }
    cout<<len<<'\n';
    for(x=0;x<seq[len].size();x++)
        cout<<seq[len][x]<<" ";
    cout<<'\n';
    return 0;


}