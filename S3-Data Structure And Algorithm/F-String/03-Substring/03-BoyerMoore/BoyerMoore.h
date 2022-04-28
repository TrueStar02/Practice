#ifndef BOYERMOORE_H_
#define BOYERMOORE_H_
#include<string>
using namespace std;
class BoyerMoore
{   private:
        string pat;
        int * right;
        int len;
    public:
        BoyerMoore(const string & str);
        ~BoyerMoore(){delete [] right;}
        int match(const string & txt) const;
        string pattern(void) const{return pat;}
};
BoyerMoore::BoyerMoore(const string & str):pat(str),len(str.length())
{   right=new int[128];
    int x;
    for(x=0;x<128;x++)
        right[x]=-1;
    for(x=0;x<len;x++)
        right[str[x]]=x;
}
int BoyerMoore::match(const string & txt) const
{   int x,y,skip;
    int tlen=txt.length();
    for(x=0;x<tlen-len+1;x+=skip)
    {   for(y=len-1;y>=0;y--)
            if(pat[y]!=txt[x+y])
            {   skip=y-right[txt[x+y]];
                if(skip<1)
                    skip=1;
                break;
            }
        if(y==-1)
            return x;
    }
    return string::npos;
}
#endif