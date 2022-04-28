#include<stdio.h>
void process(int n);
int main(void)
{   int tasks,x,n;
    scanf("%d",&tasks);
    for(x=1;x<=tasks;x++)
    {   scanf("%d",&n);
        process(n);
    }
    return 0;
}
void process(int n)
{   int arr[n+1],x,y;
    for(x=0;x<=n;x++)
        arr[x]=x;
    for(x=1;x<=n;x++)
    {   printf("%d ",arr[1]);
        arr[1]=0;
        for(y=1;y<=n-x;y++)
            arr[y-1]=arr[y+1];
        arr[n-x]=arr[0];
    }
    putchar('\n');
}