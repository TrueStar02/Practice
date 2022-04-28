#include<stdio.h>
struct people
{   int num;
    int time;
};
void process(int n);
int main(void)
{   int task,n,x;
    scanf("%d",&task);
    for(x=1;x<=task;x++)
    {   scanf("%d",&n);
        printf("test case %d:\n",x);
        process(n);
    }
    return 0;
}
void process(int n)
{   struct people stuff[n],temp;
    int x,y,t;
    for(x=0;x<n;x++)
    {   stuff[x].num=x; 
        stuff[x].time=0;
    }
     for(x=0;x<n;x++)
     for(y=1;y<=7;y++)
    {   scanf("%d",&t);
        stuff[x].time+=t;
    }
    for(x=0;x<n-1;x++)
    for(y=x+1;y<n;y++)
        if(stuff[x].time<stuff[y].time||(stuff[x].time==stuff[y].time&&stuff[x].num>stuff[y].num))
        {   temp=stuff[x];
            stuff[x]=stuff[y];
            stuff[y]=temp;
        }
    for(x=0;x<n;x++)
    {   printf("Employee %d: %d\n",stuff[x].num,stuff[x].time);
    }
}