#include<stdio.h>
int nbputs(const char *string);
int main(void)
{int n;
 char str[]="LiuYuanNiuBI";
 n=nbputs(str);
 printf("\n%d\n",n);
 return 0;
}
int nbputs(const char *string)
{int n=0;
 while(*string)
 {putchar(*string);
  string++;
  n++;
 }
 return n;
}
 
