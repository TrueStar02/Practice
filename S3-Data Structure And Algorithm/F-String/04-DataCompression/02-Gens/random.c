#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{   srand((unsigned int)time(0));
    int x,n,m;
    FILE * fp=fopen("source.txt","w");
    scanf("%d",&n);
    for(x=0;x<n;x++)
    {   m=rand()%4;
        switch(m)
        {   case 0:putc('A',fp);
                break;
            case 1:putc('G',fp);
                break;
            case 2:putc('C',fp);
                break;
            case 3:putc('T',fp);
                break;
        }
    }
    return 0;
}