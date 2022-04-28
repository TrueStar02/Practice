#include<iostream>
using namespace std;

string sort(string &s)
{   int x,y;
    char v;
    for(x=0;x<s.length()-1;x++)
    for(y=x+1;y<s.length();y++)
        if(s[x]>s[y])
        {   v=s[x];
        s[x]=s[y];
        s[y]=v;

        }
    return s;
}