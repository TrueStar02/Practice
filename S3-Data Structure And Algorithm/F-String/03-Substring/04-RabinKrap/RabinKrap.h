#ifndef RABINKRAP_H_
#define RABINKRAP_H_
#include<string>
using namespace std;
class RabinKrap
{   private:
        string pat;
        unsigned long long Q;
        unsigned long long hash;
        unsigned long long m_hash;
        int len;
    public:
        RabinKrap(const string & str);
        int match(const string & txt) const;
        string pattern(void) const{return pat;}
};
RabinKrap::RabinKrap(const string & str):Q(1000004407371007),pat(str),len(pat.length())
{   hash=0;
    m_hash=1;
    int x;
    for(x=0;x<len-1;x++)
        m_hash=(m_hash*128)%Q;
    for(x=0;x<len;x++)
        hash=(hash*128+pat[x])%Q;
}
int RabinKrap::match(const string & txt) const
{   int x;
    unsigned long long t_hash=0;
    int t_len=txt.length();
    if(t_len<len)
        return string::npos;
    for(x=0;x<len;x++)
        t_hash=(t_hash*128+txt[x])%Q;
    if(t_hash==hash)
        return 0;
    for(x=1;x<t_len-len+1;x++)
    {   t_hash=((t_hash+txt[x-1]*(Q-m_hash))*128+txt[x-1+len])%Q;
        if(t_hash==hash)
            return x;
    }
    return string::npos;
}
#endif