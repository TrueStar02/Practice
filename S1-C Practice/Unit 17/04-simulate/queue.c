#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
void InitializeQueue(Queue *pq)
{	pq->front=NULL;
	pq->rear=NULL;
	pq->items=0;
}
bool QueueIsFull(Queue *pq)
{	Node *pnode;
	pnode=(Node *)malloc(sizeof(Node));
	bool isfull=0;
	if(pnode==NULL)
		isfull=1;
	free(pnode);
	if(QueueItemCount(pq)==10)
		isfull=1;
	return isfull;
}
bool QueueIsEmpty(Queue *pq)
{	if(pq->items)
		return 0;
	else
		return 1;
}
int QueueItemCount(Queue *pq)
{	return pq->items;
}
bool EnQueue(Item item,Queue *pq)
{	Node *pnode;
	pnode=(Node *)malloc(sizeof(Node));
	if(pnode==NULL)
		return 0;
	pnode->item=item;
	pnode->next=NULL;
	if(pq->items==0)
	{	pq->front=pnode;
		pq->rear=pnode;
	}
	else
	{	pq->rear->next=pnode;
		pq->rear=pnode;
	}
	pq->items++;
	return 1;
}
bool DeQueue(Item *pitem,Queue *pq)
{	if(pq->items==0)
	{	puts("Queue is empty");
		return 0;
	}
	*pitem=pq->front->item;
	if(pq->items==1)
		InitializeQueue(pq);
	else
	{	Node *pnode=pq->front;
		pq->front=pq->front->next;
		free(pnode);
		pq->items--;
	}
	return 1;
}
void EmptyQueue(Queue *pq)
{	Item temp;
	while(!QueueIsEmpty(pq))
		DeQueue(&temp,pq);
}
