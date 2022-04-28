#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Process(char *str,int n);
int main(void)
{	int tasks,num,x;
	char str[10];
	scanf("%d",&tasks);
	for(x=1;x<=tasks;x++)
	{	scanf("%s%d",str,&num);
		Process(str,num);
	}
	return 0;
}
void Process(char *str,int n)
{	char temp[10];
	int x;
	for(x=0;x<strlen(str);x++)
		temp[strlen(str)-x-1]=str[x];
	temp[strlen(str)]='\0';
	int div=atoi(temp);
	printf("%d %d\n",div,div%n);
}
