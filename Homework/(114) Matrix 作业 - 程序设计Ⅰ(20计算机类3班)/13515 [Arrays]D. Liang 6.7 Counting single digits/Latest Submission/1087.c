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
{   int arr[10]={0};
    int x,s=0;
    for(x=0;x<n;x++)
    {   scanf("%d",&s);
        arr[s]++;
    }   
    for(x=0;x<=9;x++)
        if(arr[x]!=0)
            printf("%d %d\n",x,arr[x]);
    
   
}