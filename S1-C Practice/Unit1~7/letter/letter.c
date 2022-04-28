#include<stdio.h>
int main(void)
{int a[27],x;
 for(x=1;x<=26;x++)
 a[x]=x+96;
 for(x=1;x<=26;x++)
 printf("%c",a[x]);
 return 0;
}
