#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
int main(void)
{char str1[35]="In my opinion,",str2[21],print[35];
 nbgets(str2,21);
 sprintf(print,"%s%s",str1,str2);
 puts(print);
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
