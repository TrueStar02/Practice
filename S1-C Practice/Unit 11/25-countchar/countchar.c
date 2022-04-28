#include<stdio.h>
char *nbgets(char *st,int n);
int countchar(const char *str,char v);
int main(void)
{char words[51],ch;
 int num;
 printf("Give me a string up to 50 chars\n");
 nbgets(words,51);
 printf("Give me a letter.(Upper or lower matters.If you enter more than one,first letter matters):");
 ch=getchar();
 while(getchar()!='\n')
 continue;
 num=countchar(words,ch);
 printf("The letter %c appears %d time(s)\n",ch,num);
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
int countchar(const char *str,char v)
{int n=0;
 while(*str)
 {if(*str==v)
  n++;
  str++;
 }
 return n;
}
