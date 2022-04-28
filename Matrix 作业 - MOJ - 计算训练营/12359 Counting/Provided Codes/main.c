#include<stdio.h>
#include<ctype.h>
int main(void)
{char ch;
 int sum=0,count=0;
 while((ch=getchar())!=EOF)
 {if(isdigit(ch))
  {sum+=(ch-48);
   count++;
  }
  
 }
 printf("%d %d",count,sum);
 return 0;
}
