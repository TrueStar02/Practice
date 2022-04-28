#include<stdio.h>
unsigned long fib(int x);
int main(void)
{int num;
 unsigned long result;
 scanf("%d",&num);
 result=fib(num);
 printf("%lu",result);
 return 0;
}
unsigned long fib(int x)
{unsigned long result;
 if(x>2)
 result=fib(x-2)+fib(x-1);
 else 
 result=1;
 return result;
}
