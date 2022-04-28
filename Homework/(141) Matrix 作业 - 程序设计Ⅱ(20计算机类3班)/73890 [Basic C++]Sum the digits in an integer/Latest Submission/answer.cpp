#include<iostream>
using namespace std;
int main()
{   char c;
    int x,s=0;
    for(x=1;x<=3;x++)
    {   cin>>c;
        s+=c-48;
    }
    cout<<s;
    return 0;
}