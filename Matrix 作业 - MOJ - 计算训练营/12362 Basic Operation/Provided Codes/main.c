#include<stdio.h>
#include<math.h>
int main(void)
{int a,b;
 scanf("%d%d",&a,&b);
 printf("%d\n%d\n%d\n",a+b,a-b,a*b);
 if(b==0)
 printf("Error\n");
 else
 printf("%.2lf\n",(double)a/(double)b);
 printf("%.2lf",sqrt(a));
 return 0;
}
