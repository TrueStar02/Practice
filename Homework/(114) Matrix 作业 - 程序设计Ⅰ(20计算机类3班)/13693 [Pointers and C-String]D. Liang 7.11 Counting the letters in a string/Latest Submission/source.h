int countLetters(const char * const str)
{   int count=0,x;
    for(x=0;x<strlen(str);x++)
        if(isalpha(str[x]))
            count++;
    return count;
}