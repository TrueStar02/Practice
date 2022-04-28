#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{   srand((unsigned int)time(0));
    FILE * fp=fopen("test.in","w");
    int x,y,size;
    scanf("%d",&size);
    fprintf(fp,"%d\n",size);
    for(x=0;x<size*2;x++)
    {   for(y=0;y<size;y++)
            fprintf(fp,"%d ",rand()%9+1);
        putc('\n',fp);
    }
    fclose(fp);
    return 0;
}