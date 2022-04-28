#include<stdio.h>
int main(void)
{   int x,year;
    scanf("%d",&year);
    double fee=10000,sum=0; 
    for(x=1;x<=year+3;x++)
    {fee*=1.05;
     if(x>=year)
    sum+=fee;
    }
    printf("%.2lf",sum);
    return 0;
}