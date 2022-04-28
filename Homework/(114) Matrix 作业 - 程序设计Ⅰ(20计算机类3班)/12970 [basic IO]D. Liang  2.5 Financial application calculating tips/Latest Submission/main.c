#include<stdio.h>
int main(void)
{double subtotal,rate,gratuity,total;
 scanf("%lf%lf",&subtotal,&rate);
 gratuity=subtotal*rate/100.000;
 total=gratuity+subtotal;
 printf("%.1lf %.1lf",gratuity,total);
 return 0;
}