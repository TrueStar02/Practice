#include<stdio.h>
int main(void)
{int x,y,z;
 scanf("%d%d%d",&x,&y,&z);
 int n;
 if(x>y)
 {n=x;
  x=y;
  y=n;
 }
 if(x>z)
 {n=x;
  x=z;
  z=n;
 }
 if(y>z)
 {n=z;
  z=y;
  y=n;
 }
 printf("%d %d %d",x,y,z);
 return 0;
}