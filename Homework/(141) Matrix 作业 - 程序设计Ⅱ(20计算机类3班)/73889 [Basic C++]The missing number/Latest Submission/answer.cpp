#include<iostream>
using namespace std;
int main(void)
{   int x=15,y,z;
    for(y=1;y<=4;y++)
    {   cin>>z;
        x-=z;
    }
    cout<<x;
    return 0;
}