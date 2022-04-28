#include<stdio.h>
#include<time.h>
unsigned int rand0(void);

int main(void)
{printf("How many random numbers do you need?");
 int num,x;
 scanf("%d",&num);
 for(x=1;x<=num;x++);
 printf("%u\n",rand0());
 return 0;
}
unsigned int rand0(void)
{unsigned int seed=(unsigned int)time(0);
 seed=seed*1103515425+12345;
 return (unsigned int)(seed/65536)%32768;
}
