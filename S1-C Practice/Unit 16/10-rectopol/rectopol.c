#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct polar
{	double magnitude;
	double angle;
	double deg;
};
struct rectangle
{	double x;
	double y;
};
int main(int argc,char *argv[])
{	if(argc!=3)
	{	puts("Are you kidding?");
		exit(EXIT_FAILURE);
	}
	struct rectangle input;
	struct polar result;
	input.x=atof(argv[1]);
	input.y=atof(argv[2]);
	result.angle=atan2(input.y,input.x);
	result.magnitude=sqrt((input.y)*(input.y)+(input.x)*(input.x));
	result.deg=result.angle*(45/atan(1));
	printf("[%6.3lf,%5.3lf(%7.3lfdeg)]\n",result.magnitude,result.angle,result.deg);
	return 0;
}
