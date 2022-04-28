#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define DTR (atan(1)/45)
struct polar
{	double magnitude;
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
	struct rectangle result;
	struct polar input;
	input.magnitude=atof(argv[1]);
	input.deg=atof(argv[2]);
	result.x=input.magnitude*cos(DTR*input.deg);
	result.y=input.magnitude*sin(DTR*input.deg);
	printf("(%.3lf,%.3lf)\n",result.x,result.y);
	return 0;
}
