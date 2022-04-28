#include<stdio.h>
#include<math.h>
#define PR(X,...) printf("Message " #X ":" __VA_ARGS__)
int main(void)
{	int x;
	scanf("%d",&x);
	PR(1,"x=%d\n",x);
	PR(2,"the squareroot of %d is %lf\n",x,sqrt(x));
	return 0;
}
