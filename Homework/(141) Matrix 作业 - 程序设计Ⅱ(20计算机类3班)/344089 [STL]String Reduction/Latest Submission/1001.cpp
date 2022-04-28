#include<iostream>
#include<string>
using namespace std;
int main()
{   int n,x,y;
    string t1,t2,t3;
    size_t pos;
    cin>>n;
    for(x=1;x<=n;x++)
    {   cin>>t1>>t2>>t3;
        while((pos=t1.find(t2))!=string::npos)
        {   t1.erase(t1.begin()+pos,t1.begin()+pos+t2.size());
            t1.insert(t1.begin()+pos,t3.begin(),t3.end());

        }
        cout<<t1<<endl;
    }
    return 0;
}