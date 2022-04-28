#include<stdio.h>
int main(void)
{   int n,m,x,cd=1;
    scanf("%d%d",&m,&n);
    for(x=2;x<=m;x++)
        if(m%x==0&&n%x==0)
            cd=x;
    printf("%d",cd);
    return 0;
}