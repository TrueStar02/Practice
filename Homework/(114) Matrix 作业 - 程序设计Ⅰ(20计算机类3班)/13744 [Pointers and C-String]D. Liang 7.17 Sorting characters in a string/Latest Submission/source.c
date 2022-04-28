#include "source.h"
char* sortString(const char * const s)
{   int length=strlen(s);
    char *str=(char *)malloc(length*sizeof(char));
    strcpy(str,s);
    int x,y;
    char v;
    for(x=0;x<length-1;x++)
    for(y=x+1;y<length;y++)
    if(str[x]>str[y])
    {   v=str[x];
        str[x]=str[y];
        str[y]=v;
    }
    return str;

}