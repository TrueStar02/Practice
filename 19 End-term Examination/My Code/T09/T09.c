#include<stdio.h>
int Max(int a,int b){return (a>b)?a:b;}
void Process(int b1,int e1,int b2,int e2);
int main(void)
{	int b1,e1,b2,e2,x;
	for(x=1;x<=10;x++)
	{	scanf("%d%d%d%d",&b1,&e1,&b2,&e2);
		Process(b1,e1,b2,e2);
	}
	return 0;
}
void Process(int b1,int e1,int b2,int e2)
{	int len=Max(e2-b1,e1-b2);
	int tot=e2+e1-b2-b1;
	if(len<=tot)
		printf("true\n");
	else
		printf("false\n");
}
