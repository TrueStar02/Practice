#include<stdio.h>
#define AVG(X,Y) (2/((1/X)+(1/Y)))
int main(void)
{	puts("Enter two numbers,0 0 to quit");
	double x,y;
	while(scanf("%lf%lf",&x,&y)==2&&x*y!=0)
	{	printf("%.5lf\n",AVG(x,y));
		puts("Enter two numbers,0 0 to quit");
	}
	return 0;
}
