#include<stdio.h>

int main(void)
{unsigned long x,num;
 int isprime=1,mark;
 printf("Enter a number:");
 
 while(scanf("%lu",&num)==1)
 {for(x=1;x*x<=num;x++)
  {if(num%x==0)
   {printf("%lu=%lu*%lu\n",num,x,num/x);
    if(x!=1)
    isprime=0;
   }
  }
  if(isprime)
  printf("%lu is prime\n",num);
  isprime=1;
  printf("Enter a number:");
  
 }
 printf("Byebye\n");
 return 0;
}
