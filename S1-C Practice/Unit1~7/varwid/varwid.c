#include<stdio.h>
int main(void)
{int wid,pre;
 double num=12345.09876;
 scanf("%d%d",&wid,&pre);
 printf("%*.*lf",wid,pre,num);
 return 0;
}
