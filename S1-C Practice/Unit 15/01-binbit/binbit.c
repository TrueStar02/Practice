#include<stdio.h>
char *itob(int n,char *binary);
void prtbin(char *binary);
int main(void)
{	int num;
	char str[33];
	str[33]='\0';
	puts("Enter a number and I will transform it to binary");
	while(scanf("%d",&num))
	{	itob(num,str);
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
