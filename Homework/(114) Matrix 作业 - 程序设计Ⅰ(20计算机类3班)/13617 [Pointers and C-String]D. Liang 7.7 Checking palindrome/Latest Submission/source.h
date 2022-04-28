#include<ctype.h>
#include<string.h>
int isPalindrome(const char * const s)
{   int label=1;
    for(int x=0;x<strlen(s)/2;x++)
    {   if(tolower(s[x])!=tolower(s[strlen(s)-1-x]))
        {   label=0;
            break;
        }
    }
    return label;

}