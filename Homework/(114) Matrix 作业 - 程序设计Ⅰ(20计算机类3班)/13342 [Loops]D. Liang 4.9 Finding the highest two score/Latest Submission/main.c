#include<stdio.h>
int main(void)
{int x,y,num,max=0,sec=0;
  scanf("%d",&x);
  for(y=1;y<=x;y++)
  {scanf("%d",&num);
   if(num>max)
   {sec=max;
    max=num;
   }
   else if(num>sec)
   sec=num;
  }
  printf("%d %d",max,sec);
}