#include<stdio.h>
int main(void)
{   int num,pos=0,neg=0,tot=0,tot2,sum=0;
    printf("Kilograms      Pounds         \n");
    for(int x=1;x<=19;x++,x++)
    printf("%-15d%-15.1f\n",x,(float)x*2.2);
    return 0;
}