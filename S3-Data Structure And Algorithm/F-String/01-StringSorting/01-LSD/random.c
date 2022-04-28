#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{   srand((unsigned int)time(0));
    FILE *fp=fopen("test.txt","w");
    int m,n;
    scanf("%d%d",&m,&n);
    int x,y;
    char v;
    for(x=0;x<m;x++)
    {   for(y=0;y<n;y++)
            fputc((char)(rand()%95+32),fp);
        fputc('\n',fp);
    }
    fclose(fp);
    return 0;
}