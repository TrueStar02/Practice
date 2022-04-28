#include<stdio.h>
int main(void)
{   int x,y,neg=0,tot=0,tot2,sum=0;
    printf("Miles          Kilometers     Kilometers     Miles          \n");
    for(x=1,y=20;x<=10;x++,y+=5)
    printf("%-15d%-15.3f%-15d%-15.3f\n",x,(float)x*1.609,y,(float)y/1.609);
    return 0;
}