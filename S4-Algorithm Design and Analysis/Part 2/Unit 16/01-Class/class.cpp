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
{   int x,n;
    cin>>n;
    Course arr[n];
    for(x=0;x<n;x++)
        cin>>arr[x].first>>arr[x].second;
    sort(arr,arr+n,comp());
    vector<int> picked;
    int cur=0;
    picked.push_back(0);
    for(x=1;x<n;x++)
        if(arr[x].first>=arr[cur].second)
        {   picked.push_back(x);
            cur=x;
        }
    cout<<picked.size();
    cout<<endl;
    for(x=0;x<picked.size();x++)
        cout<<picked[x]<<" ";
    cout<<endl;
    return 0;
}
