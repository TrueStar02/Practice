#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
int main(void)
{char str1[51]="In my opinion,",str2[21],str3[21];
 nbgets(str2,21);
 strncat(str1,str2,20);
 nbgets(str3,20);
 strncpy(str1+strlen(str1),str3,50-strlen(str1));
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
