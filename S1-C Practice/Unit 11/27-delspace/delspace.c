#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
void delspace(char *str);
int main(void)
{char words[51];
 while(nbgets(words,51)&&words[0]!='\0')
 {delspace(words);
  puts(words);
 }
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
void delspace(char *str)
{char temp[51];
 int i=0,x;
 for(x=0;str[x]!='\0';x++)
 {if(str[x]!=' ')
  temp[x-i]=str[x];
  else
  i++;
 }
 temp[x]='\0';
 strcpy(str,temp);
}
