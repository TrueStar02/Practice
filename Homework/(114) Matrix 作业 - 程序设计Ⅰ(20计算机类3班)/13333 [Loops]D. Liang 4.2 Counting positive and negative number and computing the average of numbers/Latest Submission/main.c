#include<stdio.h>
int main(void)
{   int num,pos=0,neg=0,tot=0,sum=0;
    scanf("%d",&num);
    while(num!=0)
    {tot++;
     if(num>0)
     pos++;
     else if(num<0)
     neg++;
     sum+=num;
     scanf("%d",&num);
    }
    
    if(tot==0)
    printf("0 0 0 0.00");
    else
    {double ave;
    
    ave=(double)sum/(double)tot;
    
    printf("%d %d %d %.2lf",pos,neg,sum,ave);
    }
    return 0;
}