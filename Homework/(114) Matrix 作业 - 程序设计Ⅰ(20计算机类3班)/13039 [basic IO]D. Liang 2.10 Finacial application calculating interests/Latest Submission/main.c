#include<stdio.h>
int main(void)
{double balance,rate,interest;
 scanf("%lf%lf",&balance,&rate);
 interest=balance*(rate/1200.0);
 printf("%.1lf",interest);
 return 0;
}