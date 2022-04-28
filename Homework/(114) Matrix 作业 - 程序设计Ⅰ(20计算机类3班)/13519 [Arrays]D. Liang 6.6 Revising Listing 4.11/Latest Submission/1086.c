#include<stdio.h>
int main(void)
{   int x=0,y=2,z,isprime,n;
    scanf("%d",&n);
    while(x<n)
    {   isprime=1;
        for(z=2;z*z<=y;z++)
            if(y%z==0)
            {   isprime=0;
                break;
            }
        if(isprime==1)
        {   printf("%d",y);
            x++;
            if(x<n)
            printf(" ");
        }
        y++;
    }
    printf("\n");
    return 0;
}