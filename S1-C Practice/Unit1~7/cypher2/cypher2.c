#include<stdio.h>
#include<ctype.h>
int main(void)
{char ch;
 ch=getchar();
 while(ch!='\n')
 {if(isalpha(ch))
  ch++;
  putchar(ch);
  ch=getchar();
 }
 putchar(ch);
 return 0;
}
