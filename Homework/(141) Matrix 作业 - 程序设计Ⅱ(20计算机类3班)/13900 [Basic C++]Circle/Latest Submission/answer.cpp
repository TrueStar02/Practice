#include<iostream>
using namespace std;
const double PI=3.14159265358979; 
int main()
{   double r;
    cin>>r;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout.precision(8);
    cout<<r*r*PI;
    return 0;
}