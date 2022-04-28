int * count(const char * const s)
{   int *count=(int *)malloc(10*sizeof(int));
    int x;
    for(x=0;x<10;x++)
        count[x]=0;
    for(x=0;x<strlen(s);x++)
        if(isdigit(s[x]))
            count[s[x]-48]++;
    return count;

}