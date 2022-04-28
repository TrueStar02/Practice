#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char *nbgets(char *st,int n);
int main(void)
{char words[21],*end,*end2;
 nbgets(words,21);
 double num=strtod(words,&end);
 long power=strtol(end+1,&end2,10);
 printf("%lf\n",pow(num,power));
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
