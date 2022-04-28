#include<iostream>
using namespace std;
int main()
{   int a,b;
    cin>>a>>b;
    cout<<a/b<<endl;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout.precision(2);
    cout<<(double)a/b;
    return 0;
}