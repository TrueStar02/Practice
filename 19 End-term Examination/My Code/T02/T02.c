#include<stdio.h>
int main(void)
{	int arr[10],tasks,num,x,y,temp;
	scanf("%d",&tasks);
	for(x=1;x<=tasks;x++)
	{	for(y=0;y<=9;y++)
			arr[y]=0;
		scanf("%d",&num);
		for(y=1;y<=num;y++)
		{	temp=y;
			while(temp>0)
			{	arr[temp%10]++;
				temp/=10;
			}
		}
		for(y=0;y<=9;y++)
			printf("%d ",arr[y]);
		putchar('\n');
	}
	return 0;
}
