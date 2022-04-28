#include "stdio.h"
#include "head.h"

int main(){
	int n;
	scanf("%d", &n);
	long f = factorial(n);
	printf("%ld\n",f);
	return 0;
}

