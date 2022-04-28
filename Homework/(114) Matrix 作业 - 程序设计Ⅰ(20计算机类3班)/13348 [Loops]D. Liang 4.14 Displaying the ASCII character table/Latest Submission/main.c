#include<stdio.h>
int main(void)
{   int x,y;
    scanf("%d",&x);
    char v;
    for(y=1,v='!';v<='~';y++,v++)
    {printf(" %c ",v);
     if(y%x==0)
     printf("\n");
    }
}