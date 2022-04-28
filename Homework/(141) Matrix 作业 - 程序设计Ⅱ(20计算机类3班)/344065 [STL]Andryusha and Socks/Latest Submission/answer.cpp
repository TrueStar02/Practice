#include<iostream>
#include<set>
using namespace std;
int main()
{   set<int> s;
    int max=0;
    int n,x,m;
    cin>>n;
    for(x=0;x<2*n;x++)
    {   cin>>m;
        if(s.find(m)!=s.end())
            s.erase(m);
        else
            s.insert(m);
        if(s.size()>max)
            max=s.size();
    }
    cout<<max;
    return 0;
}