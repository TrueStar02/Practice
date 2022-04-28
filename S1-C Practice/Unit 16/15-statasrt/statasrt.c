#include<stdio.h>
#define TEST 5
_Static_assert(TEST==0,"ERROR");
int main(void)
{	puts("Succeed!");
	return 0;
}
