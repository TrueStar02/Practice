#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "stack.h"
char Choice(void);
int getnumber(void);
int main(void)
{	Stack line;
	Item temp;
	char ch;
	InitializeStack(&line);
	while((ch=Choice())!='q')
	{	switch(ch)
		{	case 'a':
				printf("Enter an interger:\n");
				temp=getnumber();
				if(StackIsFull(&line))
					puts("Stack is full!");
				else
				{	EnStack(temp,&line);
					printf("%d added\n",temp);
				}
				break;
			case 'd':
				if(DeStack(&temp,&line))
					printf("%d removed\n",temp);
				else
					printf("Stack is empty!\n");
				break;
		}
		printf("%d item(s) contained\n",StackItemCount(&line));
	}
	EmptyStack(&line);
	puts("Bye~");
	return 0;
}
char Choice(void)
{	char ch;
	puts("Choose option:");
	puts("A-Add D-Delete Q-Quit");
	while((ch=tolower(getchar()))&&strchr("adq",ch)==NULL)
	{	while(getchar()!='\n')
			continue;
		puts("Enter A,D or Q!");
	}
	while(getchar()!='\n')
			continue;
	return ch;
}
int getnumber(void)
{	int temp;
	while(scanf("%d",&temp)!=1)
	{	while(getchar()!='\n')
			continue;
		puts("Enter an interger between 0 and 10!");
	}
	while(getchar()!='\n')
		continue;
	return temp;
}
