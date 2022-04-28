#include<stdio.h>
int main(void)
{char ch;
 unsigned long space=0,enter=0,other=0;
 while((ch=getchar())!='#')
 {if(ch=='\n')
  enter++;
  else if(ch==' ')
  space++;
  else 
  other++;
 }
 printf("%luspaces %luenters %luother chars\n",space,enter,other);
 return 0;
} 
