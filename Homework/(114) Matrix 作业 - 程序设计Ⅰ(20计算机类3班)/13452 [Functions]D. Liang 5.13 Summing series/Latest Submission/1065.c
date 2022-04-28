#include <stdio.h>
int main(void)
{
	int n;
	int i,a,b;
	float sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a=i;
		b=a+1;
		sum=sum+1.0*a/b;
	}
	printf("%.4f\n",sum);
	return 0;
}