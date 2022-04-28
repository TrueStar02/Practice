#include<stdio.h>
int main(void)
{   int num,s,x;
    double goal;
    scanf("%d",&num);
    for(x=1;x<=num;x++)
    {   scanf("%lf",&goal);
        if(goal<=5400)
            printf("%.0lf\n",(goal-5000)/0.08);
        else if(goal<=5900)
            printf("%.0lf\n",(goal-5400)/0.1+5000);
        else   
            printf("%.0lf\n",(goal-5900)/0.12+10000);
    }
    return 0;
}