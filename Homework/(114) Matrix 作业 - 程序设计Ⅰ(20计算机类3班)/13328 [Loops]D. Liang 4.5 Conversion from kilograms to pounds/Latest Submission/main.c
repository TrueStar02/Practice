#include<stdio.h>
int main(void)
{   int x,y,neg=0,tot=0,tot2,sum=0;
    printf("Kilograms      Pounds         Pounds         Kilograms      \n");
    for(x=1,y=20;x<=19;x++,x++,y+=5)
    printf("%-15d%-15.2f%-15d%-15.2f\n",x,(float)x*2.2,y,(float)y/2.2);
    return 0;
}