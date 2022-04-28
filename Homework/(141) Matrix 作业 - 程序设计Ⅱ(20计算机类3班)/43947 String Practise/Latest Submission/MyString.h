#include<iostream>
using namespace std;
string MyStringPractise(const string &s1, const string &s2)
{   string t;
    if(s1.length()>=3)
        t+=s1.substr(0,3);
    else
        t+=s1;
    if(s2.length()>=3)
        t+=s2.substr(s2.length()-3,3);
    else
        t+=s2;
    return t;
}