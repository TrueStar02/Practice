#include<stdio.h>
#include<ctype.h>
#include<string.h>
char *nbgets(char *st,int n);
char getfirst(void);
void orgorder(char *str[],int n);
void ascorder(char *str[],int n);
void lenorder(char *str[],int n);
void fstorder(char *str[],int n);
void print(void);
int fstwd(char *str);
int main(void)
{int n,x;
 printf("This program can order the strings in various ways.\n");
 printf("How many strings do you need to order?\n");
 while(scanf("%d",&n)!=1)
 {printf("Interger only!\n");
  while(getchar()!='\n')
  continue;
 }
 getchar();
 char words[n][51],ch,*ptr[n];
 for(x=0;x<n;x++)
 {printf("Enter string %d/%d\n",x+1,n);
  nbgets(words[x],51);
  while(words[x][0]=='\0')
  {printf("You haven't entered anything!Enter string %d/%d again!\n",x+1,n);
   nbgets(words[x],51);
  }
 }
 print();
 while((ch=getfirst())!='Q')
 {for(x=0;x<n;x++)
  ptr[x]=words[x];
  switch(ch)
  {case 'A':orgorder(ptr,n);
            break;
   case 'B':ascorder(ptr,n);
            break;
   case 'C':lenorder(ptr,n);
            break;
   case 'D':fstorder(ptr,n);
            break;
   default :printf("Take it seriously!\n");
  }
   print();
 }
 printf("Bye-bye~\n");
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
char getfirst(void)
{char v;
 v=getchar();
 v=toupper(v);
 while(getchar()!='\n')
 continue;
 return v;
}
void orgorder(char *str[],int n)
{int x;
 for(x=0;x<n;x++)
 puts(str[x]);
}
void ascorder(char *str[],int n)
{int x,y;
 char *ptr;
 for(x=0;x<n-1;x++)
 for(y=x+1;y<n;y++)
 {if(strcmp(str[x],str[y])>0)
  {ptr=str[x];
   str[x]=str[y];
   str[y]=ptr;
  }
 }
 orgorder(str,n);
}
void lenorder(char *str[],int n)
{int x,y;
 char *ptr;
 for(x=0;x<n-1;x++)
 for(y=x+1;y<n;y++)
 {if(strlen(str[x])>strlen(str[y]))
  {ptr=str[x];
   str[x]=str[y];
   str[y]=ptr;
  }
 }
 orgorder(str,n);
}
void fstorder(char *str[],int n)
{int x,y,temp;
 char *ptr;
 int fstlen[n];
 for(x=0;x<n;x++)
 fstlen[x]=fstwd(str[x]);
 for(x=0;x<n-1;x++)
 for(y=x+1;y<n;y++)
 {if(fstlen[x]>fstlen[y])
  {ptr=str[x];
   str[x]=str[y];
   str[y]=ptr;
   temp=fstlen[x];
   fstlen[x]=fstlen[y];
   fstlen[y]=temp;
  }
 }
 orgorder(str,n);
}
int fstwd(char *str)
{int x;
 for(x=0;str[x]!=' '&&str[x]!='\0';x++);
 return x;
}
void print(void)
{printf("How to order the strings?\n");
 printf("A-Original Order          B-ASCII Order\n");
 printf("C-Length Order            D-First Word's Length Order\n");
 printf("Q-Quit\n");
}
