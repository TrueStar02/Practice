#include<stdio.h>
#include<ctype.h>
int main(void)
{char ch;
 while((ch=getchar())!='\n')
 {if(isupper(ch))
  printf("%.3hhd",ch+36);
  else if(islower(ch))
  printf("%.3hhd",ch-96);
  else if(ch==' ')
  printf("000");
 }
 return 0;
}
