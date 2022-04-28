#include<iostream>
#include<algorithm>
#include<vector>
const double eps=1e-8;
using namespace std;
int main()
{   int x,n;
    cin>>n;
    double point[n];
    for(x=0;x<n;x++)
        cin>>point[x];
    sort(point,point+n);
    int count=1;
    vector<double> left(1,point[0]);
    for(x=1;x<n;x++)
    {
        if(left[count-1]+1+eps<point[x])
        {   left.push_back(point[x]);
            count++;
        }
    }
    cout<<count<<"\n";
    for(x=0;x<count;x++)
        cout<<left[x]<<" ";
    cout<<endl;
    return 0;
}