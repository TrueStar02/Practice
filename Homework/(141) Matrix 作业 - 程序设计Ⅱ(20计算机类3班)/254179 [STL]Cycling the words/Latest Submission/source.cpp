#include<iostream>
#include<vector>
using namespace std;
int main()
{   vector<string> v;
    int x,y;
    string t;
    while(cin>>t)
        v.push_back(t);
    for(x=0;x<v.size();x++)
    {   for(y=x;;y=(y+1)%v.size())
        {   cout<<v[y]<<" ";
            if(y==x-1||!x&&y==v.size()-1)
                break;
        }
        cout<<endl;
    }
    return 0;
}