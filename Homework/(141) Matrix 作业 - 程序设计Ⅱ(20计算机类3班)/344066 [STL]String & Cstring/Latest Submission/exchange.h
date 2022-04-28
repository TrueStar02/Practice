#include<string>
#include<cstring>
using namespace std;
std::string change1(const char* cstr){return cstr;}
void change2(std::string str, char* cstr)
{   
    strcpy(cstr,str.c_str());
}