#include<stdio.h>
void task(int n);
int main(void)
{   int n,x,num;
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {   scanf("%d",&num);
        task(num);
    }
    return 0;
}
void task(int n)
{
    int max=-1000000000,frq=0,num,x;
    for(x=0;x<n;x++)
    {   scanf("%d",&num);
        if(num>max)
        {   max=num;
            frq=1;
        }
        else if(num==max)
            frq++;
    }
    
    printf("%d %d\n",max,frq);
}