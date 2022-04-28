#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void initialize(struct queue* q)
{   q->front=0;
    q->tail=-1;
    q->elements=(int *)malloc(sizeof(int)*10000);
}
int pop(struct queue* q)
{   if((q->tail)<(q->front))
        return -1;
    q->front++;
    return q->elements[q->front-1];

}
int push(struct queue* q, int number)
{   if(get_size(q)>=100)
        return -1;
    q->tail++;
    q->elements[q->tail]=number;
    return number;
}
int get_size(struct queue* q)
{   return (q->tail)+1-(q->front);
}
int get_front(struct queue* q)
{   if(empty(q))
        return -1;
    return q->elements[q->front];
}
int empty(struct queue* q)
{   if(q->front>q->tail)
        return 1;
    return 0;
}
void list(struct queue* q)
{   int x;
    if(empty(q))
        puts("Empty queue");
    else
    {    for(x=q->front;x<q->tail;x++)
            printf("%d ",q->elements[x]);
        printf("%d\n",q->elements[q->tail]);
    }
}