#include<iostream>
using namespace std;
int main()
{   double a,b;
    cin>>a>>b;
    cout<<a+b<<endl<<a-b<<endl<<a*b<<endl;
    if(b)
        cout<<a/b<<endl;
    else
        cout<<0<<endl;
    return 0;
}