#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> Course;
struct comp
{
    bool operator()(const Course & c1,const Course & c2){return c1.second<c2.second;}
};
int main()
{   int x,y,n;
    cin>>n;
    Course arr[n];
    for(x=0;x<n;x++)
        cin>>arr[x].first>>arr[x].second;
    sort(arr,arr+n,comp());
    vector<vector<int>> picked(1,vector<int>());
    vector<int> cur;
    cur.push_back(0);
    picked[0].push_back(0);
    for(x=1;x<n;x++)
    {   for(y=0;y<picked.size();y++)
            if(arr[x].first>=arr[cur[y]].second)
            {   picked[y].push_back(x);
                cur[y]=x;
                break;
            }
        if(y==picked.size())
        {   cur.push_back(x);
            picked.push_back(vector<int>(1,x));
        }
    }
    cout<<picked.size();
    cout<<endl;
    for(y=0;y<picked.size();y++)
    {   for(x=0;x<picked[y].size();x++)
            cout<<picked[y][x]<<" ";
        cout<<endl;
    }
    return 0;
}