#include "isInSet.h"
#include<iostream>
bool isInH(const string & s)
{   if(s.length()%2==0)
        return 0;
    int x;
    for(x=0;x<=s.length()/2;x++)
    {   if(s[x]!='0'&&s[x]!='1')
            return 0;
        if(s[x]!=s[s.length()-1-x])
            return 0;
    }
    return 1;
}