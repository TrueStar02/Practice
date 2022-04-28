#include<stdio.h>
int main(void)
{register int x=8;
 int *ptr,y;
 ptr=&x;
 y=*ptr;
 printf("%d\n",y);
 return 0;
}
