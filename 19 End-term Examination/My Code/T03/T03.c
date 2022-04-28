#include<stdio.h>
int Common(int x,int y);
int Total(int num,int start);
int main(void)
{	int tasks,num,start,x;
	scanf("%d",&tasks);
	for(x=1;x<=tasks;x++)
	{	scanf("%d%d",&num,&start);
		printf("%d\n",Total(num,start));	
	}
	return 0;
}
int Common(int x,int y)
{	int temp;
	if(x<y)
	{	temp=x;
		x=y;
		y=temp;
	}
	while(x%y!=0)
	{	temp=x%y;
		x=y;
		y=temp;
	}
	return y;
}
int Total(int num,int start)
{	int mst,x;
	for(x=1;x<=num;x++)
	{	scanf("%d",&mst);
		if(start>=mst)
			start+=mst;
		else
			start+=Common(start,mst);
	}
	return start;
}
