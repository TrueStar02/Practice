#include<stdio.h>
int main(void)
{char ch;
 int num=0;
 while((ch=getchar())!='.')
 {if(ch!='\"'&&ch!='\'')
  num++;
 }
 printf("%d",num);
 return 0;
}
