#include<stdio.h>
#include<math.h>
void task(int num);
int main(void)
{   int tasks,x,num;
    scanf("%d",&tasks);
    for(x=1;x<=tasks;x++)
    {   scanf("%d",&num);
        task(num);
    }
    return 0;
}
void task(int num)
{   int x,sum=0,sum2=0,temp;
    for(x=1;x<=num;x++)
    {   scanf("%d",&temp);
        sum+=temp;
        sum2+=temp*temp;
    }
    printf("%.2f %.2f\n",(float)sum/num,sqrt(((float)sum2-(sum*sum)/(float)num)/(num-1)));
}