#include<stdio.h>
#include<math.h>
int main(void)
{   int x;
    printf("      Degree         Sin         Cos\n");
    for(x=0;x<=360;x+=10)
        printf("%12d%12.4lf%12.4lf\n",x,sin((double)x),cos((double)(x)));
    return 0;
}