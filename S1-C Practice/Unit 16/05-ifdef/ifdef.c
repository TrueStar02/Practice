#include<stdio.h>
#define IMSB 2
int main(void)
{	
	#ifdef IMSB
		printf("I'm SB!\n");
	#else
		printf("You are SB!\n");
	#endif
	return 0;
}
