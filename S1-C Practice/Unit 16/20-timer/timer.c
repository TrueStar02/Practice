#include<stdio.h>
#include<time.h>
int main(void)
{	int s=0;
	printf("CPS:%ld\n",CLOCKS_PER_SEC);
	clock_t start=clock();
	while((clock()-start)<=0.6*CLOCKS_PER_SEC)
		s++;
	printf("s=%d\n",s);
	return 0;
}
