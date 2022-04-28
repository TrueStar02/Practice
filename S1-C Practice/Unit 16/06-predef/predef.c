#include<stdio.h>
void URSB(void);
int main(void)
{	printf("This function is %s\n",__func__);
	printf("The file if %s\n",__FILE__);
	printf("Today is %s\n",__DATE__);
	printf("Now is %s\n",__TIME__);
	printf("The version is %ld\n",__STDC_VERSION__);
	printf("This is line %d\n",__LINE__);
	URSB();
}
void URSB(void)
{	printf("This function is %s\n",__func__);
	printf("This is line %d\n",__LINE__);
}
