#include<stdio.h>
unsigned long factor(int num);
int main()
{int num;
 unsigned long result;
 scanf("%d",&num);
 result=factor(num);
 printf("%ld\n",result);
 return 0;
}
unsigned long factor(int num)
{unsigned long result=1;
 if(num>1)
 result=num*factor(num-1);
 return result;
}
