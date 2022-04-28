#include<stdio.h>
#include<ctype.h>
char *nbgets(char *st,int n);
void camel(char *str);
int main(void)
{char words[81];
 nbgets(words,81);
 camel(words);
 puts(words);
 return 0;
}
char *nbgets(char *st,int n)
{char *ptr;
 ptr=fgets(st,n,stdin);
 int i=0;
 if(ptr)
 {while(st[i]!='\0'&&st[i]!='\n')
  i++;
  if(st[i]=='\n')
  st[i]='\0';
  else
  while(getchar()!='\n')
  continue;
 }
 return ptr;
}
void camel(char *str)
{int i=0;
 while(*str)
 {if(isalpha(*str))
  {i++;
   if(i%2==0)
   *str=tolower(*str);
   else
   *str=toupper(*str);
  }
  else
  i=0;
  str++;
 }
}
