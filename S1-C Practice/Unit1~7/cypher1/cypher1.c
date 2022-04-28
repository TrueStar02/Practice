#include<stdio.h>
#define SPACE ' '
int main(void)
{char ch;
 ch=getchar();
 while(ch!='\n')
 {if(ch!=SPACE)
  ch++;
  putchar(ch);
  ch=getchar();
 }
 putchar(ch);
 return 0;
}
