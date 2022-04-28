#include<stdio.h>
#include<stdlib.h>
void SignOff(void);
void URSB(void);
int main(void)
{	int x;
	atexit(SignOff);
	if(!scanf("%d",&x))
	{	atexit(URSB);
		exit(EXIT_FAILURE);
	}
	printf("The number %d is %s\n",x,(x%2)?"Odd":"Even");
	return 0;
}
void SignOff(void)
{	printf("This is a programme by Edward\n");
}
void URSB(void)
{	printf("You are a big SB!!!\n");
}
