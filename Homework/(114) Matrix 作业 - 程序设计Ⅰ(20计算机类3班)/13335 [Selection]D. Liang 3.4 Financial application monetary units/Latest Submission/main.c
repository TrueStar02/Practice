#include<stdio.h>
int main(void)
{
    long num,dollar,quarter,dime,nickel,pennie,n;
    scanf("%ld",&num);
    n=num;
    pennie=num%5;
    num-=pennie;
    dollar=(num-num%100)/100;
    num-=dollar*100;
    quarter=(num-num%25)/25;
    num-=quarter*25;
    dime=(num-num%10)/10;
    num-=dime*10;
    nickel=num/5;
    printf("Your amount %ld consists of\n",n);
    if(dollar>0) 
    {printf("%ld dollar",dollar);
     if(dollar>1)
     printf("s");
     printf("\n");
    }
    if(quarter>0)
    {printf("%ld quarter",quarter);
     if(quarter>1)
     printf("s");
     printf("\n");
    }
    if(dime>0)
    {printf("%ld dime",dime);
     if(dime>1)
     printf("s");
     printf("\n");
    }
    if(nickel>0)    
    {printf("%ld nickel",nickel);
     if(nickel>1)
     printf("s");
     printf("\n");
    }
    if(pennie>1)
    printf("%ld pennies",pennie);
    else if(pennie==1)
    printf("%ld penny",pennie);
}