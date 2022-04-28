#include<stdio.h>
int main(void)
{   int year,x;
    double rate,money,now=0.0;
    scanf("%lf%lf",&money,&rate);
    for(x=1;x<=6;x++)
    now=(now+money)*(1.0+rate/1200.0);
    printf("%.2lf",now);
    return 0;
}