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
{   int arr[n],avg=0;
    int x,s=0;
    for(x=0;x<n;x++)
       scanf("%d",arr+x);
    for(x=0;x<n;x++)
    printf("%d ",*(arr-x+n-1));  
    printf("\n");
   
}