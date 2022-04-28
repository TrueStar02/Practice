#include<stdio.h>
unsigned int move(unsigned int num,int n);
int main(void)
{	unsigned int num;
	int mov;
	scanf("%u%d",&num,&mov);
	printf("%u\n",move(num,mov));
	return 0;
}
unsigned int move(unsigned int num,int n)
{	int x,i;
	if(n>0)
		for(x=1;x<=n;x++)
		{	i=0;
			if(num>>31)
				i=1;
			num<<=1;
			num+=i;
		}
	else if(n<0)
		for(x=1;x<=-n;x++)
		{	i=0;
			if(num&1)
				i=1;
			num>>=1;
			num+=(i<<31);
		}
	return num;
}
