#ifndef QUEUE_H_
#define QUEUE_H
#include<stdbool.h>
typedef int Item;
struct node
{	Item item;
	struct node * next;
};
typedef struct node Node;
struct queue
{	Node *front;
	Node *rear;
	int items;
};
typedef struct queue Queue;
void InitializeQueue(Queue *pq);
bool QueueIsFull(Queue *pq);
bool QueueIsEmpty(Queue *pq);
int QueueItemCount(Queue *pq);
bool EnQueue(Item item,Queue *pq);
bool DeQueue(Item *pitem,Queue *pq);
void EmptyQueue(Queue *pq);
#endif
