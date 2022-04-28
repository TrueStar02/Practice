#include<cstdlib>
#include<string>
using namespace std;
char * convertDecimalToHex(int value)
{   string t;
    while(value>0)
    {   if(value%16<10)
            t+=char(value%16+48);
        else
            t+=char(value%16+55);
        value/=16;
    }
    char *str=new char[t.length()+1];
    int x;
    for(x=0;x<t.length();x++)
        str[x]=t[t.length()-1-x];
    str[t.length()]='\0';
    return str;

}
void convertDecimalToHex(int value, char *s)
{    string t;
    while(value>0)
    {   if(value%16<10)
            t+=char(value%16+48);
        else
            t+=char(value%16+55);
        value/=16;
    }
    
    int x;
    for(x=0;x<t.length();x++)
        s[x]=t[t.length()-1-x];
    s[t.length()]='\0';

}