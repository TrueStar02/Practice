#include<stdio.h>
#define MYTYPE(X) _Generic((X),int:"int",float:"float",double:"double",int *:"int pointer",float *:"float pointer",double *:"double pointer",default:"other")
int main(void)
{	int d=5;
	printf("%s\n",_Generic((d),int:"int",float:"float",double:"double",int *:"int pointer",float *:"float pointer",double *:"double pointer",default:"other"));
	printf("%s\n",MYTYPE(2.0*d));
	printf("%s\n",MYTYPE((float)d));
	printf("%s\n",MYTYPE(&d));
	return 0;
}
