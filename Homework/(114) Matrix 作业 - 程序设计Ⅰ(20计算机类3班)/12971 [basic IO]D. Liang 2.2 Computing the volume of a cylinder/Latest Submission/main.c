#include<stdio.h>
#define PI 3.14159
int main(void)
{double radius,area,length,volume;
 scanf("%lf%lf",&radius,&length);
 volume=radius*radius*PI*length;
 printf("%.4lf",volume);
 return 0;
}
