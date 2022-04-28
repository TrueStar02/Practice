#include<stdio.h>
#include<ctype.h>
int main(void)
{int n,x,legal=1;
 char ch;
 scanf("%d",&n);
 ch=getchar();
 for(x=1;x<=n;x++)
 {legal=1;
  ch=getchar();
  if(!(isalpha(ch)||ch=='_'))
  legal=0;
  while((ch=getchar())!='\n')
  {if(!(isalpha(ch)||ch=='_'||isdigit(ch)))
    legal=0;
  }
  if(legal==1)
  printf("Yes\n");
  else 
  printf("No\n");
 }
}
