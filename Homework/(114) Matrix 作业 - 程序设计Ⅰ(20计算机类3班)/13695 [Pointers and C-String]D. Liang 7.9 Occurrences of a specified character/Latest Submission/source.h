int count(const char * const str, char ch)
{   int count=0,x;
    for(x=0;x<strlen(str);x++)
        if(str[x]==ch)
            count++;
    return count;
}