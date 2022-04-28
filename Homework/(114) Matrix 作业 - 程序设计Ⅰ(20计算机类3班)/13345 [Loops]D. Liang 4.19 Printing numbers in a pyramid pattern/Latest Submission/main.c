#include<stdio.h>
int main(void)
{int pow[8]={1,2,4,8,16,32,64,128};
 int line,x,y;
 scanf("%d",&line);
 for(x=1;x<=line;x++)
 {for(y=1;y<=line-x;y++)
  printf("     ");
  for(y=1;y<=x;y++)
  printf("%5d",pow[y-1]);
  for(y=x-1;y>=1;y--)
  printf("%5d",pow[y-1]);
  printf("\n");
 }
 return 0;
}