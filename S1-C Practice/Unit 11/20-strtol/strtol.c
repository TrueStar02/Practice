#include<stdio.h>
#include<stdlib.h>
char *nbgets(char *st,int n);
int main(void)
{char num[21];
 nbgets(num,21);
 char *end;
 long value;
 value=strtol(num,&end,10);
 printf("DEC to DEC:%ld\n",value);
 value=strtol(num,&end,16);
 printf("HEX to DEC:%ld\n",value); 
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
