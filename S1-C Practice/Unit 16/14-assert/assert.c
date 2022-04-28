#include<stdio.h>
#define NDEBUG
#include<assert.h>
#include<math.h>
int main(void)
{	double x,y,z;
	puts("Enter two sides of a triangle");
	while(scanf("%lf%lf",&x,&y)==2&&(x>0)&&(y>0))
	{	z=x*x-y*y;
		assert(z>0);
		printf("The answer is %lf\n",sqrt(z));
		puts("Enter two sides of a triangle");
	}
	return 0;
}
