#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
class NumberParseException{};
bool isNumber(const char* str)
{   int m=0;
	string s(str);
    if(s.empty())return 0;
    if((s[0]=='+'||s[0]=='-')&&s.length()!=1) m=1;
    return s.find_first_not_of("1234567890",m)==string::npos;
}
int parseNumber(const char *str)
{   
    char * p;
    if(str==NULL||!isNumber(str))
        throw NumberParseException();
    return strtol(str,&p,10);
}