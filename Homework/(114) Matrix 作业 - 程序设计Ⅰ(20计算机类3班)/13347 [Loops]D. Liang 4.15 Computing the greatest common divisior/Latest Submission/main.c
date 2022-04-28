#include<stdio.h>
int main(void)
{int num1,num2,x,max=1;
 scanf("%d%d",&num1,&num2);
 for(x=2;x<=num1;x++)
 if(num1%x==0&&num2%x==0)
 max=x;
 printf("%d",max);
 return 0;
}