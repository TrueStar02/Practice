#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
int main(void)
{char str[10][31];
 int i=0,j;
 for(i=0;i<10;i++)
 {if(!(nbgets(str[i],31))||!strcmp(str[i],"quit"))
  break;
  if(i==9)
  i++;
 }
 for(j=0;j<i;j++)
 puts(str[j]);
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
