#include<stdio.h>
char *nbgets(char *st,int n);
int main(void)
{char words[21];
 nbgets(words,21);
 puts(words);
 return 0;
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
