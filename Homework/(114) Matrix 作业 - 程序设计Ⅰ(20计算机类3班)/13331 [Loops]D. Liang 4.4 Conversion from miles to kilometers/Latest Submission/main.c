#include<stdio.h>
int main(void)
{   int num,pos=0,neg=0,tot=0,tot2,sum=0;
    printf("Miles          Kilometers     \n");
    for(int x=1;x<=10;x++)
    printf("%-15d%-15.3f\n",x,(float)x*1.609);
    return 0;
}