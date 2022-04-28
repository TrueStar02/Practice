#include<stdio.h>
int main(void)
{int weight,cost;
 printf("ounces cost\n");
 for(weight=1,cost=40;weight<=50;weight++,cost+=20)
 printf("%5d $%5.2f\n",weight,cost/100.0);
 return 0;
}
