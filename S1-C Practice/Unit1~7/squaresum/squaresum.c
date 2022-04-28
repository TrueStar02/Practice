#include<stdio.h>
long squaresum(int min,int max);
int main(void)
{int min,max,label;
 long result;
 printf("Enter two numbers:");
 label=scanf("%d%d",&min,&max);
 while(label==2&&min<=max)
 {result=squaresum(min,max);
  printf("%ld\n",result);
  printf("Enter two numbers:");
  label=scanf("%d%d",&min,&max);
 }
 printf("Byebye\n");
 
 return 0;
}
long squaresum(int min,int max)
{int x;
 long sum=0;
 for(x=min;x<=max;x++)
 sum+=x*x;
 return sum;
}
