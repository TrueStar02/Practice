#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main(void)
{double length;
 scanf("%lf",&length);
 printf("%.3lf %.3lf %.3lf",sqrt(length),sqrt(length/PI),0.5*PI*length);
 return 0;
}
