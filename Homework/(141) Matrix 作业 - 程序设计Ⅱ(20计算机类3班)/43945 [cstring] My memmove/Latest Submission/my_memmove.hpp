#include<iostream>
using namespace std;
char* my_memmove(char *dst, const char *src, unsigned int n)
{   int x;
    char tmp[n];
    for(x=0;x<n;x++)
        tmp[x]=src[x];
    for(x=0;x<n;x++)
        dst[x]=tmp[x];
    return dst;
}