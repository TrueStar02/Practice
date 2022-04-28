#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{   srand((unsigned int)time(0));
    int x,y,len,m,n;
    FILE * fp=fopen("test.txt","w");
    scanf("%d%d",&m,&n);
    for(x=0;x<m;x++)
    {   len=rand()%n+1;
        for(y=0;y<len;y++)
            putc((char)(rand()%26+97),fp);
        putc('\n',fp);
    }
    fclose(fp);
    return 0;
}