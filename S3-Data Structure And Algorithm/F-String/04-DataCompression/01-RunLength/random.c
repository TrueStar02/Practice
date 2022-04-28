#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{   srand((unsigned int)time(0));
    int x,n,m;
    FILE * fp=fopen("source.txt","w");
    _Bool state=0;
    scanf("%d",&n);
    for(x=0;x<n;x++)
    {   m=rand()%50;
        for(;m>0;m--)
            putc(state+48,fp);
        state^=1;
    }
    return 0;
}