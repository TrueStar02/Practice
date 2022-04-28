#include<iostream>
#include<string>
using namespace std;
int main()
{   int n,x,count,sum,y;
    cin>>n;
    string t;
    for(x=0;x<n;x++)
    {   cin>>t;
        count=10;
        sum=0;
        for(y=0;y<11;y++)
        {   if(t[y]!='-')
            {   sum+=count*(t[y]-48);
                count--;
            }
        }
        cout<<t<<"-";
        if(sum%11!=1)
            cout<<11-sum%11<<endl;
        else
            cout<<"X\n";
    }

}