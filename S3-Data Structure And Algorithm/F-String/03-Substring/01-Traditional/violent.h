#ifndef VIOLENT_H_
#define VIOLENT_H_
#include<string>
using namespace std;
int match(const string & txt,const string & pat)
{   int x,len=txt.length();
    int y,plen=pat.length();
    for(x=0;x<len-plen+1;x++)
    {   for(y=0;y<plen;y++)
            if(txt[x+y]!=pat[y])
                break;
        if(y==plen)
            return x;
    }
    return string::npos;
}
#endif