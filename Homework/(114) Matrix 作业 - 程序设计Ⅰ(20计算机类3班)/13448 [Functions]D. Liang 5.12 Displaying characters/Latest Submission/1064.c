#include<stdio.h>
int main(void)
{   int n,x;
    char ch1,ch2;
    ch1=getchar();
    getchar();
    ch2=getchar();
    getchar();
    scanf("%d",&n);
    if(ch1<=ch2)
        for(x=1;ch1<=ch2;x++,ch1++)
            {   putchar(ch1);
                if(x%n==0)
                    printf("\n");
            }
    else
        for(x=1;ch1>=ch2;x++,ch2++)
            {   putchar(ch2);
                if(x%n==0)
                    printf("\n");
            }
    return 0;
}