#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{   srand((unsigned int)time(0));
    int x,y,l;
    FILE *fp=fopen("test.in","w");
    for(x=1;x<=10000;x++)
    {   fprintf(fp,"%d ",rand()%90000+10000);
        l=6+rand()%10;
        for(y=1;y<=l;y++)
            putc(rand()%26+97,fp);
        putc('\n',fp);
    }
    return 0;
}