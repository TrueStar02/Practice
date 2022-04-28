#include<stdio.h>
#include<math.h>
int main(void)
{long sum=0,num,x,y,cof,dig;
 scanf("%ld%ld",&num,&x);
 for(y=1;y<=num;y++)
 {scanf("%ld%ld",&cof,&dig);
  if(dig==0)
  continue;
  sum+=cof*dig*pow(x,dig-1);
 }
 printf("%ld",sum);
 return 0;
}
