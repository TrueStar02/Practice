#include<stdio.h>
int main(void)
{	int num=0;
	char ch;
	while((ch=getchar())!=EOF)
	{	putchar(ch);
		num++;
	}
	printf("\nTotal:%d\n",num);
	return 0;
}
