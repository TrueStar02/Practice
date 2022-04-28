#include<stdio.h>
#include<ctype.h>
char *readchars(char *str,int n);
int main(void)
{int n;
 char ch[51],*pt;
 pt=readchars(ch,31);
 puts(ch);
 printf("%p\n",pt);
 return 0;
}
char *readchars(char *str,int n)
{char v;
 int i=0;
 while((v=getchar())!='\n'&&(!isblank(v))&&i<n-1)
 {str[i]=v;
  i++;
 }
 str[i]='\0';
 if(v!='\n')
 while(getchar()!='\n')
 continue;
 return str;
}
