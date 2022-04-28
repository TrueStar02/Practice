#include<stdio.h>
#include<string.h>
#include<ctype.h>
unsigned int btod(char *binary);
char *nbgets(char *st,int n);
int main(void)
{	char binary[33];
	nbgets(binary,31);
	printf("%u\n",btod(binary));
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
