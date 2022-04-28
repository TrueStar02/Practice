#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{   int n,temp,x,y;
    cin>>n;
    string t;
    for(x=0;x<pow(2,n);x++)
    {   t=string(2*n-1,'0');
        temp=x;
        for(y=0;y<n;y++)
        {  if(temp%2)
             t[n-1-y]=t[n-1+y]='1';
            temp/=2;
        }
        cout<<t<<endl;
    }
    return 0;
}