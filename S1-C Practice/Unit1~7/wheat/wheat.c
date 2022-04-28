#include<stdio.h>
#define CROPS 2E16
int main(void)
{int x;
 long double cur=1.00,tot=0.00;
 
 for(x=1;x<=64;x++)
 {tot+=cur;
  printf("%2d,%15.5lle,%15.5lle,%15.5lle\n",x,cur,tot,tot/CROPS);
  cur*=2;
 }
 
}
