#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void randpick(int *arr,int size,int num);
int main(void)
{	int arr[500],x,num;
	for(x=0;x<500;x++)
		arr[x]=x+1;
	printf("How many numbers do you need(0 to quit)?\n");
	while(scanf("%d",&num)==1&&num>0)
	{	if(num>=500)
			puts("Too many numbers!");
		else
			randpick(arr,500,num);
		printf("How many numbers do you need(0 to quit)?\n");
	}
	return 0;
}
void randpick(int *arr,int size,int num)
{	srand((unsigned int)time(0));
	int x,temp,index;
	for(x=1;x<=num;x++)
	{	index=rand()%size;
		printf("%4d",arr[index]);
		temp=arr[index];
		arr[index]=arr[size-1];
		arr[size-1]=temp;
		size--;
		if(x%10==0)
			putchar('\n');
	}
	if(x%10!=1)
		putchar('\n');
}
