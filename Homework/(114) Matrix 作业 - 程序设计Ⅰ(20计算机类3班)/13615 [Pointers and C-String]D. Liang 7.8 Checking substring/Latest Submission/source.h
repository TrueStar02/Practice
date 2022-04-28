#include<string.h>
int indexOf(const char *s1, const char *s2)
{   char *label=strstr(s2,s1);
    if(label==NULL)
        return -1;
    else
        return (label-s2);
}