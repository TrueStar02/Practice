#include<stdio.h>
int main(void)
{int ia=134567789,ib=-5044,ic=300;
 printf("%d %o %x %#x\n",ia,ia,ia,ia);
 printf("%d %u %X %#o\n",ib,ib,ib,ib);
 printf("%d %6.1d %c %f\n",ic,ic,ic,ic);
 double da=18.6,db=-3.44,dc=114514.19198101;
 printf("%lf %e %g %a\n",da,da,da,da);
 printf("%lf %6.1lf %d %#g\n",db,db,db,db);
 printf("%lf %+020lf % 20.5e %a\n",dc,dc,dc,dc);
 return 0;
}
