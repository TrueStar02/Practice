#include<stdio.h>
double power(double x,int exp);
int main()
{double x,xpow;
 int exp,label;
 printf("Enter p&q,we will calculate p^q\n");
 label=scanf("%lf%d",&x,&exp);
 while(label==2)
 {xpow=power(x,exp);
  printf("%.6g^%d=%.8g\n",x,exp,xpow);
  printf("Enter p&q,we will calculate p^q");
  label=scanf("%lf%d",&x,&exp);
 }
 printf("Byebye!\n");
 return 0;
}
double power(double x,int exp)
{double pow=1.0;
 int y;
 for(y=1;y<=exp;y++)
 pow*=x;
 return pow;
}
