#include<iostream>
using namespace std;
int main()
{   double m;
    int n,x;
    cin>>n;
    for(x=0;x<n;x++)
    {   cin>>m;
        cout<<m<<endl;
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<m<<endl;
        cout.unsetf(ios_base::floatfield);

    }
    return 0;
}