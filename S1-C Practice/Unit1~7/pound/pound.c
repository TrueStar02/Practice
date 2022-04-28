#include<stdio.h>
int main(void)
{int i=8;
 char c='0';
 float f=3.0;
 pound(i);
 pound(c);
 pound((int)f);
 return 0;
}
void pound(int n)
{while(n-->0)
 printf("#");
 printf("\n");
}
