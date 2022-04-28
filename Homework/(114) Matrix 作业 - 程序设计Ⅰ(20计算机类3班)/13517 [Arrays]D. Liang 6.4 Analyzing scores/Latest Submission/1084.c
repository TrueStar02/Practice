#include<stdio.h>
void task(void);
int main(void)
{   int n,x,num;
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {   task();
    }
    return 0;
}
void task(void)
{   int arr[100],x,y,s=0;
    double avg=0;
    for(x=0;scanf("%d",arr+x)&&arr[x]>=0;x++)
        continue;
    for(y=0;y<x;y++)
        avg+=(double)arr[y];
    avg/=x;
    for(y=0;y<x;y++)
        if(arr[y]>=avg)
            s++;
    printf("%d %d\n",s,x-s);

}