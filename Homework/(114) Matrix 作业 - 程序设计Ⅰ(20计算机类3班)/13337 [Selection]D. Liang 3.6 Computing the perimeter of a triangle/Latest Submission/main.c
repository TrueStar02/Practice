#include<stdio.h>
int main(void)
{   
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    if((x+y>z)&&(x+z>y)&&(y+z>x))
    printf("%d",x+y+z);
    else
    printf("invalid");
    return 0;
}