#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{   int n,x;
    string s;
    while(cin>>s)
    {   s[0]=toupper(s[0]);
        cout<<s<<" ";
    }
    return 0;

}