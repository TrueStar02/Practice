#include<stdio.h>
int main(void)
{int div,x,y,z,lab=1;
 double max;
 scanf("%d%lf",&div,&max);
 for(x=2;x<=div;x++)
 for(y=1;(double)y/(double)x<=max;y++)
 {for(z=2;z<=y;z++)
  if(x%z==0&&y%z==0)
  {label=0;
   break;
  }
  if(label==1)
  printf("%d/%d\n",y,x);
  label=1;
 }
 return 0;
}
