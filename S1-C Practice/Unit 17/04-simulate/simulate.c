#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "queue.h"
bool NewCustomer(double CusPerHour);
Item CustomerTime(long when);
int main(void)
{	Item temp;
	long cycle,cyclelimit;
	long accepted=0,turnaway=0,served=0;
	double MinPerCust;
	Queue line;
	int CustPerHour;
	long TotalWaitingTime=0;
	int WaitingTime=0;
	long TotalSize=0;
	srand((unsigned int)time(0));
	printf("Simulating hours:");
	scanf("%ld",&cyclelimit);
	printf("Average customers per hour:");
	scanf("%d",&CustPerHour);
	InitializeQueue(&line);
	for(cycle=0;cycle<=cyclelimit*60;cycle++)
	{	if(NewCustomer(CustPerHour))
		{	temp=CustomerTime(cycle);
			if(QueueIsFull(&line))
				turnaway++;
			else
			{	EnQueue(temp,&line);
				accepted++;
			}
		}
		if(WaitingTime==0&&(!QueueIsEmpty(&line)))
		{	DeQueue(&temp,&line);
			WaitingTime=temp.processtime;
			served++;
			TotalWaitingTime+=cycle-temp.arrive;
		}
	
		TotalSize+=QueueItemCount(&line);
		if(WaitingTime>0)
			WaitingTime--;
	}
	printf("Customers Accepted:%ld\n",accepted);
	printf("Customers Served:%ld\n",served);
	printf("Customers Turned-away:%ld\n",turnaway);
	printf("Average Line Size:%.2lf\n",(double)TotalSize/(cyclelimit*60));
	printf("Average Waiting Time:%.2lf\n",(double)TotalWaitingTime/served);
	EmptyQueue(&line);
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
	temp.processtime=rand()%3+1;
	return temp;
	
}
