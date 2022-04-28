#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
int main(void)
{char str1[31],str2[21];
 nbgets(str1,21);
 nbgets(str2,21);
 strncat(str1,str2,30-strlen(str1));
 puts(str1);
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
