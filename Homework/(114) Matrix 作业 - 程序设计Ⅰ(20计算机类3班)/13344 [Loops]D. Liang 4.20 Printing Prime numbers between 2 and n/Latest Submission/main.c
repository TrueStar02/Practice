#include<stdio.h>
int main(void)
{int max,x,y,n=0,isprime;
 scanf("%d",&max);
 for(x=2;x<=max;x++)
 {isprime=1;
  for(y=2;y*y<=x;y++)
  if(x%y==0)
  {isprime=0;
   break;
  }
  if(isprime==1)
  {n++;
   printf("%5d",x);
   if(n%8==0)
   printf("\n");
  }
 }
}