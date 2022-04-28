#include<stdio.h>
int main(void)
{
    long num,dollar,quarter,dime,nickle,pennie,n;
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
    nickle=num/5;
    printf("Your amount %ld consists of\n",n); 
    printf("%ld dollars\n",dollar);
    printf("%ld quarters\n",quarter);
    printf("%ld dimes\n",dime);
    printf("%ld nickels\n",nickle);
    printf("%ld pennies\n",pennie);
}