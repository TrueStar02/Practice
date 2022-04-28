#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
void inversechar(char *str);
int main(void)
{char words[51];
 nbgets(words,51);
 inversechar(words);
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
void inversechar(char *str)
{char temp[51];
 int x;
 strcpy(temp,str); 
 for(x=0;x<=strlen(str)-1;x++)
 str[x]=temp[strlen(str)-1-x];
}
