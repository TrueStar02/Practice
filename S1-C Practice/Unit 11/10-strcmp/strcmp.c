#include<stdio.h>
#include<string.h>
#define NB "Xu Yuerao"
char *nbgets(char *st,int n);
int main(void)
{char str[21];
 int i;
 puts("Who is the NBest person?");
 nbgets(str,21);
 i=strcmp(str,NB);
 while(i)
 {printf("You are wrong!%s is not NB enough!\n",str);
  puts("Consider seriously!Who is the NBest person?");
  nbgets(str,21);
  i=strcmp(str,NB);
 }
 puts("Yes!Xu Yuerao is the NBest!She is too NB at all!");
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
