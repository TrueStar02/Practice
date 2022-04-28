#include<stdio.h>
#include<math.h>
#define DTR (atan(1)/45)
#define SQRT(X) _Generic((X),float:sqrtf(X),long double:sqrtl(X),default:sqrt(X))
#define SIN(X) _Generic((X),float:sinf(X*DTR),long double:sinl(X*DTR),default:sin(X*DTR))
int main(void)
{	float x=45.0f;
	double xx=45.0;
	long double xxx=45.0l;
	printf("%.17f\n",SQRT(x));
	printf("%.17lf\n",SQRT(xx));
	printf("%.17llf\n",SQRT(xxx));
	printf("%.17f\n",SIN(x));
	printf("%.17lf\n",SIN(xx));
	printf("%.17llf\n",SIN(xxx));
	return 0;
}
