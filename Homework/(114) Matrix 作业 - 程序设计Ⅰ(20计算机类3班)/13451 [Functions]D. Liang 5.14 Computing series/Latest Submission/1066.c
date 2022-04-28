#include<stdio.h>
int main(void)
{   double sum=4;
    int x,n;
    scanf("%d",&n);
    for(x=1;x<=n;x++)
        if(x%2==0)
            sum+=4.0/(2*x+1);
        else
            sum-=4.0/(2*x+1);
    printf("%.5lf",sum);
    return 0;

}