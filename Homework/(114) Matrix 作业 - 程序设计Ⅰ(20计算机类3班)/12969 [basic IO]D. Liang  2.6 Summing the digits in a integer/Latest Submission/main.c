#include<stdio.h>
int main(void)
{int x,y=0;
 scanf("%d",&x);
 y=y+x%10;
 x=(x-x%10)/10;
 y=y+x%10;
 x=(x-x%10)/10;
 y=y+x;
 printf("%d",y);
 return 0;
}