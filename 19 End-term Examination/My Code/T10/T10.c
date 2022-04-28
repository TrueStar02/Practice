#include<stdio.h>
void Number(int n);
int main(void)
{	int num,label=0,inzero=0;
	scanf("%d",&num);
	printf("RenMinBi");
	int ori=num;
	if(num==1000000000)
		printf("ShiYi");
	else
	{	if(num/100000000)
		{	inzero=0;
			Number(num/100000000);
			printf("Yi");
			label++;
		}
		num%=100000000;
		if(num/10000000)
		{	inzero=0;
			Number(num/10000000);
			label++;
			printf("Qian");
		}
		else
		{	if(label)
				inzero=1;
		}
		num%=10000000;
		if(num/1000000)
		{	if(inzero)
				printf("Ling");
			inzero=0;
			Number(num/1000000);
			label++;
			printf("Bai");
		}
		else
		{	if(label)
				inzero=1;
		}
		num%=1000000;
		if(num/100000)
		{	if(inzero)
				printf("Ling");
			inzero=0;
			if(num/100000!=1||label)
				Number(num/100000);
			label++;
			printf("Shi");
		}
		else
		{	if(label)
				inzero=1;
		}
		num%=100000;
		if(num/10000)
		{	if(inzero)
				printf("Ling");
			inzero=0;
			Number(num/10000);
			label++;
		}
		else
		{	if(label)
				inzero=1;
		}
		if((ori/10000)%10000)
			printf("Wan");
		num%=10000;
		if(num/1000)
		{	inzero=0;
			Number(num/1000);
			label++;
			printf("Qian");
		}
		else
		{	if(label)
				inzero=1;
		}
		num%=1000;
		if(num/100)
		{	if(inzero)
				printf("Ling");
			inzero=0;
			Number(num/100);
			label++;
			printf("Bai");
		}
		else
		{	if(label)
				inzero=1;
		}
		num%=100;
		if(num/10)
		{	if(inzero)
				printf("Ling");
			inzero=0;
			if(num/10!=1||label)
				Number(num/10);
			label++;
			printf("Shi");
		}
		else
		{	if(label)
				inzero=1;
		}
		num%=10;
		if(num)
		{	if(inzero)
				printf("Ling");
			inzero=0;
			Number(num);
			label++;
		}
		else
		{	if(label)
				inzero=1;
		}
	}
	printf("YuanZheng");
	return 0;
}

void Number(int n)
{	int iszero=0;
	switch(n)
	{	case 0:	iszero=1;
				break;
		case 1:	printf("Yi");
				break;
		case 2:	printf("Er");
				break;
		case 3:	printf("San");
				break;
		case 4:	printf("Si");
				break;
		case 5:	printf("Wu");
				break;
		case 6:	printf("Liu");
				break;
		case 7:	printf("Qi");
				break;
		case 8:	printf("Ba");
				break;
		case 9:	printf("Jiu");
				break;
	}

}
