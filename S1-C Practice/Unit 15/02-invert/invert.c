#include<stdio.h>
char *itob(int n,char *binary);
void prtbin(char *binary);
int invert(int n,int size);
int main(void)
{	int num,size;
	char str[33];
	str[33]='\0';
	puts("Enter a number and I will transform it to binary and inverse some of its bits");
	while(scanf("%d%d",&num,&size)==2)
	{	puts("Origin:");
		itob(num,str);
		prtbin(str);
		printf("We have inverse %d in the last %d bits\n",num,size);
		num=invert(num,size);
		itob(num,str);
		prtbin(str);
	}
	puts("Bye~");
	return 0;
}
char *itob(int n,char *binary)
{	int x;
	for(x=31;x>=0;x--,n>>=1)
		binary[x]=(n&01)+48;
	return binary;
}
void prtbin(char *binary)
{	int x;
	for(x=0;x<=31;x++)
	{	putchar(binary[x]);
		if(x%4==3)
			putchar(' ');
	}
	putchar('\n');
}
int invert(int n,int size)
{	int mask=0,x;
	for(x=1;x<=size;x++)
	{	mask<<=1;
		mask++;
	}
	n^=mask;
	return n;
}
