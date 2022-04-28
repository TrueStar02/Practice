#include<stdio.h>
#include<math.h>
int main(void)
{   int min,max,x;
    scanf("%d%d",&min,&max);
    printf("      Number  SquareRoot\n");
    for(x=min;x<=max;x++)
       printf("%12d%12.4lf\n",x,sqrt((double)x));
    return 0;
    


}