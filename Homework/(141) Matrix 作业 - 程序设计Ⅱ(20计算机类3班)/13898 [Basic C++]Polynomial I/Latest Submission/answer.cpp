#include<iostream>
using namespace std;
int main(void)
{   int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    cout<<a1*a2<<"x^2";
    cout.setf(ios_base::showpos);
    cout<<b1*a2+a1*b2<<"x"<<b2*b1;
    return 0;
}