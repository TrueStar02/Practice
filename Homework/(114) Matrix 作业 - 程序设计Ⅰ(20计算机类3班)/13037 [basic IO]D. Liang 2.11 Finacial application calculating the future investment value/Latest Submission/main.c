#include<stdio.h>
int main(void)
{   int year,x;
    double rate,money;
    scanf("%lf%lf%d",&money,&rate,&year);
    for(x=1;x<=year*12;x++)
    money=money*(1.0+rate/1200.0);
    printf("%.2lf",money);
    return 0;
}