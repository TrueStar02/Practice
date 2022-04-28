#include<stdio.h>
#include<ctype.h>
int main(void)
{char ch;
 while((ch=getchar())!='\n')
 {if(isalpha(ch))
  putchar(tolower(ch));
 }
 return 0;
}
