#include<stdio.h>
#include<string.h>
unsigned int btod(char *binary);
char *dtob(unsigned int n,char *binary);
char *nbgets(char *st,int n);
int main(void)
{	char binary1[33],binary2[33],result[33];
	puts("Enter the binary number 1");
	nbgets(binary1,31);
	puts("Enter the binary number 2");
	nbgets(binary2,31);
	unsigned num1=btod(binary1),num2=btod(binary2);
	printf("%s & %s = %s\n",dtob(num1,binary1),dtob(num2,binary2),dtob(num1&num2,result));
	printf("%s | %s = %s\n",dtob(num1,binary1),dtob(num2,binary2),dtob(num1|num2,result));
	printf("%s ^ %s = %s\n",dtob(num1,binary1),dtob(num2,binary2),dtob(num1^num2,result));
	return 0;
}
unsigned int btod(char *binary)
{	unsigned int num=0;
	int x;
	for(x=0;x<strlen(binary);x++)
		if(binary[strlen(binary)-x-1]=='1')
			num+=(1<<x);
	return num;
}
char *dtob(unsigned int n,char *binary)
{	binary[32]='\0';
	int x;
	for(x=0;x<=31;x++)
	{	binary[31-x]=(n&1)+48;
		n>>=1;
	}
	return binary;
}
char *nbgets(char *st,int n)
{	char *ptr;
 	ptr=fgets(st,n,stdin);
 	int i=0;
 	if(ptr)
 	{	while(st[i]!='\0'&&st[i]!='\n')
  			i++;
  		if(st[i]=='\n')
  			st[i]='\0';
  		else
  			while(getchar()!='\n')
 				continue;
 	}
 	return ptr;
}
