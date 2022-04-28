#include<stdio.h>
int count(unsigned int n);
int isOpen(unsigned int n,unsigned int p);
int main(void)
{	unsigned int num,pos;
	scanf("%u%u",&num,&pos);
	printf("%d %s\n",count(num),isOpen(num,pos)==1?"True":"False");
	return 0;
}
int count(unsigned int n)
{	int s=0,x;
	for(x=1;x<=32;x++)
	{	if(n&1)
			s++;
		n>>=1;
	}
	return s;
}
int isOpen(unsigned int n,unsigned int p)
{	int m=0;
	if((n>>(p-1))&1)
		m=1;
	return m;
}
