#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{   double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout.precision(2);
    cout<<fabs((x1 - x2)*( y3 - y2)-(x3 - x2) *(y1 - y2)) * 0.5;
    return 0;
}