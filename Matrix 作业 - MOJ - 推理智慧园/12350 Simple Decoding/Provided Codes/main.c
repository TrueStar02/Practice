#include<stdio.h>
int main(void)
{int num;
 while(scanf("%3d",&num)==1)
 {if(num==0)
  printf(" ");
  else if(num<100)
  printf("%c",num+96);
  else
  printf("%c",num-36);
 }
 return 0;
}
