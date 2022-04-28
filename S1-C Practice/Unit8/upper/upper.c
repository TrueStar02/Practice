#include<stdio.h>
#include<ctype.h>
int main(void)
{int upper=0,lower=0,other=0;
 char ch;
 while((ch=getchar())!=EOF)
 {if(islower(ch))
  lower++;
  else if(isupper(ch))
  upper++;
  else
  other++;
 }
 printf("Upper letters:%d Lower letters:%d Other chars:%d\n",upper,lower,other);
 return 0;
}
