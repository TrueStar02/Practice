#include<stdio.h>
#include<string.h>
char *searchspace(const char *str);
char *nbgets(char *st,int n);
int main(void)
{char words[51],*ptr;
 nbgets(words,51);
 ptr=searchspace(words);
 if(*ptr)
 *ptr='#';
 puts(words);
}
char *nbgets(char *st,int n)
{char *ptr;
 ptr=fgets(st,n,stdin);
 if(ptr)
 {while(*st!='\0'&&*st!='\n')
  st++;
  if(*st=='\n')
  *st='\0';
  else
  while(getchar()!='\n')
  continue;
 }
 return ptr;
}
char *searchspace(const char *str)
{char *ptr;
 ptr=strchr(str,' ');
 return ptr;
}
