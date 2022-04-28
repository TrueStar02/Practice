char* prefix(const char * const s1, const char * const s2)
{   int x;
    int lenmin=strlen(s1);
    if(lenmin>strlen(s2));
    lenmin=strlen(s2);
    for(x=0;x<strlen;x++)
        if(s1[x]!=s2[x])
            break;
    char *ch=(char *)malloc((x+1)*sizeof(char));
    if(!x)
        ch[0]='\0';
    else
        strncpy(ch,s1,x);
    return ch;
}