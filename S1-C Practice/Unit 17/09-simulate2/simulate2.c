#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "queue.h"
bool NewCustomer(double CusPerHour);
Item CustomerTime(long when);
int main(void)
{	Item temp;
	int x;
	long cycle,cyclelimit;
	long accepted=0,turnaway=0,served=0;
	double MinPerCust;
	Queue line[2];
	int CustPerHour;
	long TotalWaitingTime=0;
	int WaitingTime[2]={0,0};
	long TotalSize=0;
	srand((unsigned int)time(0));
	printf("Simulating hours:");
	scanf("%ld",&cyclelimit);
	printf("Average customers per hour:");
	scanf("%d",&CustPerHour);
	InitializeQueue(&line[0]);
	InitializeQueue(&line[1]);
	for(cycle=0;cycle<=cyclelimit*60;cycle++)
	{	if(NewCustomer(CustPerHour))
		{	temp=CustomerTime(cycle);
			if(QueueIsFull(&line[1])&&QueueIsFull(&line[0]))
				turnaway++;
			else
			{	if(QueueItemCount(&line[0])>QueueItemCount(&line[1]))
					EnQueue(temp,&line[1]);
				else
					EnQueue(temp,&line[0]);
				accepted++;
			}
		}
		for(x=0;x<2;x++)
		{	if(WaitingTime[x]==0&&(!QueueIsEmpty(&line[x])))
			{	DeQueue(&temp,&line[x]);
				WaitingTime[x]=temp.processtime;
				served++;
				TotalWaitingTime+=cycle-temp.arrive;
			}
			TotalSize+=QueueItemCount(&line[x]);
			if(WaitingTime[x]>0)
				WaitingTime[x]--;
			
		}
	}
	printf("Customers Accepted:%ld\n",accepted);
	printf("Customers Served:%ld\n",served);
	printf("Customers Turned-away:%ld\n",turnaway);
	printf("Average Line Size:%.2lf\n",(double)TotalSize/(cyclelimit*120));
	printf("Average Waiting Time:%.2lf\n",(double)TotalWaitingTime/served);
	EmptyQueue(&line[1]);
	EmptyQueue(&line[0]);
	puts("Bye~");
	return 0;
}
bool NewCustomer(double CusPerHour)
{	if((rand()%60+1)<=CusPerHour)
		return 1;
	else
		return 0;
}
Item CustomerTime(long when)
{	Item temp;
	temp.arrive=when;
	temp.processtime=rand()%5+1;
	return temp;
	
}
