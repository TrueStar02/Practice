#include<stdio.h>
#include<string.h>
char *nbgets(char *st,int n);
int main(void)
{char words[25][51];
 char *ptr[25],*swap;
 int i=0,j,k;
 while(nbgets(words[i],51)&&i<50&&(words[i][0]!='\0'))  
 {ptr[i]=words[i];
  i++;
 }
 for(j=0;j<i;j++)
 for(k=j+1;k<i;k++)
 {if(strcmp(ptr[j],ptr[k])>0)
  {swap=ptr[j];
   ptr[j]=ptr[k];
   ptr[k]=swap;
  }
 }
 for(j=0;j<i;j++)
 puts(ptr[j]); 
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

