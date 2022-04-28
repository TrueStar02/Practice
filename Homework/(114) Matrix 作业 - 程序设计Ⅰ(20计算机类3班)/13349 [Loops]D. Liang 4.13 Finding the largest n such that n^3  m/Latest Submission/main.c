#include<stdio.h>
int main(void)
{int x,m;
 scanf("%d",&m);
 for(x=1;x*x*x<m;x++)
 continue;
 x--;
 printf("%d",x);
 return 0;
}