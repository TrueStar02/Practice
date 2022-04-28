#include<stdio.h>
int main(void)
{int num,x=2,y,fac=1;
 scanf("%d",&num);
 while(x<=num)
 {for(y=2;y*y<=x;y++)
  if(x%y==0)
  {fac=0;
   continue;
  }
  if(fac==0)
  {x++;
   fac=1;
   continue;
  }
  if(num%x==0)
  {printf("%d\n",x);
   num/=x;
  }
  else
  x++;
  fac=1;
 }
  return 0;
}