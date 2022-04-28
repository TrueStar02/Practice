#include<iostream>
using namespace std;
bool foo(int n);
int main()
{   int tasks,x,n;
    cin>>tasks;
    for(x=0;x<tasks;x++)
    {   cin>>n;
        bool i=foo(n);
        if(i)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
bool foo(int n)
{   bool mat[n][n];
    int x1,y1,x2,y2;
    for(x1=0;x1<n;x1++)
    for(y1=0;y1<n;y1++)
        cin>>mat[x1][y1];
    for(x1=0;x1<n;x1++)
    for(y1=0;y1<n;y1++)
    if(mat[x1][y1])
    {   x2=y1;
        for(y2=0;y2<n;y2++)
        if(mat[x2][y2])
        {   if(!mat[x1][y2])
                return 0;
        }
    }
    return 1;
}