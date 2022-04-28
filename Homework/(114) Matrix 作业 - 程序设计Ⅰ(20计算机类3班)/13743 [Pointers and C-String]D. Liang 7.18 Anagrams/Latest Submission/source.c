int isAnagram(const char * const s1, const char * const s2)
{   int len=strlen(s1),x,y;
    if(len!=strlen(s2))
        return 0;
    char str1[len+1],str2[len+1],ch;
    strcpy(str1,s1);
    strcpy(str2,s2);
    for(x=0;x<len-1;x++)
    for(y=x+1;y<len;y++)
    {   if(str1[x]>str1[y])
        {   ch=str1[x];
            str1[x]=str1[y];
            str1[y]=ch;
        }
        if(str2[x]>str2[y])
        {   ch=str2[x];
            str2[x]=str2[y];
            str2[y]=ch;
        }
    }
    return !strcmp(str1,str2);
}