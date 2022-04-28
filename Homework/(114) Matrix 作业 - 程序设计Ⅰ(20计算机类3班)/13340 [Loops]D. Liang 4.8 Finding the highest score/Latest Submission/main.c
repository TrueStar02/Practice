#include<stdio.h>
int main(void)
{int x,y,num,max=0;
  scanf("%d",&x);
  for(y=1;y<=x;y++)
  {scanf("%d",&num);
   if(num>max)
   max=num;
  }
  printf("%d",max);
}