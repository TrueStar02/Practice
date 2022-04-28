#ifndef KMP_H_
#define KMP_H_
#include<string>
using namespace std;
class KMP
{   private:
        int ** dfa;
        string pat;
        int state;
        int len;
    public:
        KMP(const string & str);
        ~KMP();
        int match(const string & txt);
        string pattern(void) const{return pat;}
};
KMP::KMP(const string & str)
{   dfa=new int*[128];
    int x,y,reset;
    len=str.length();
    for(x=0;x<128;x++)
        dfa[x]=new int[len];
    for(x=0;x<128;x++)
        dfa[x][0]=0;
    dfa[str[0]][0]=1;
    for(x=1,reset=0;x<len;reset=dfa[str[x]][reset],x++)
    {   for(y=0;y<128;y++)
            dfa[y][x]=dfa[y][reset];
        dfa[str[x]][x]=x+1;
    }
}
KMP::~KMP()
{   int x;
    for(x=0;x<128;x++)
        delete [] dfa[x];
    delete [] dfa;
}
int KMP::match(const string & txt) 
{   state=0;
    int x;
    for(x=0;x<txt.length();x++)
    {   state=dfa[txt[x]][state];
        if(state==len)
            return x-len+1;
    }
    return string::npos;
}
#endif