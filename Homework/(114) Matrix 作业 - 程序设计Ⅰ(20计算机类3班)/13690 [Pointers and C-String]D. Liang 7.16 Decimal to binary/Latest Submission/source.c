#include "source.h"
char* convertDecimalToBinary(int value)
{   char *str=(char *)malloc(32*sizeof(char));
    char ch;
    int x=0;
    while(value>0)
    {   
        sprintf(str+x,"%d",value%2);
        value/=2;
        x++;
    }
    for(x=0;x<strlen(str)/2;x++)
    {   ch=str[x];
        str[x]=str[strlen(str)-x-1];
        str[strlen(str)-x-1]=ch;
    }
    return str;
}