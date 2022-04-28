#include<stdio.h>
int main(void)
{int x,y,n;
 scanf("%d",&n);
 if(n>0&&n<=26)
 for(x=1;x<=n;x++)
 {for(y=1;y<=n-x;y++)
  printf(" ");
  for(y=1;y<=x;y++)
  printf("%c",64+y);
  for(y=x-1;y>=1;y--)
  printf("%c",64+y);
  printf("\n");
 }
 else
 printf("error\n");
 return 0;
}
