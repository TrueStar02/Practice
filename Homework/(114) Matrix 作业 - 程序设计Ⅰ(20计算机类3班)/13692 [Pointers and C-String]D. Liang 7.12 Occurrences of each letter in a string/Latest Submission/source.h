int * countLetters(const char * const s)
{   int *letters=(int *)malloc(sizeof(int)*26);
    int x;
    for(x=0;x<=25;x++)
        letters[x]=0;
    for(x=0;x<strlen(s);x++)
        if(isalpha(s[x]))
            letters[toupper(s[x])-65]++;
    return letters;
}