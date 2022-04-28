#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
int main(void)
{char str1[50],str2[30];
 nbgets(str1,30);
 nbgets(str2,30);
 strcat(str1,str2);
 puts(str1);
 puts(str2);
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
