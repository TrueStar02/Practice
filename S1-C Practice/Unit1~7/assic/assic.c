#include<stdio.h>
#include<ctype.h>
int main(void)
{char ch;
 int num=0;
 while((ch=getchar())!='#')
 {if(isspace(ch))
  continue;
  num++;
  putchar(ch);
  printf(" %3hhd ",ch);
  if(num%8==0)
  printf("\n");
 }
 if(num%8)
 printf("\n");
 return 0;
}
