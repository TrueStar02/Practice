#include<stdio.h>
#include<math.h>
void root(double num,double eps);
int main(void)
{   int tasks,x;
    double num,eps;
    scanf("%d",&tasks);
    for(x=1;x<=tasks;x++)
    {   scanf("%lf%lf",&num,&eps);
        root(num,eps);

    }
}
void root(double num,double eps)
{   double last=1,now=-1;
    now=(last+num/last)/2;
    while((now-last)>=eps||(now-last)<-eps)
    {   last=now;
        now=(last+num/last)/2;

    }
    printf("%.8lf\n",now);
}