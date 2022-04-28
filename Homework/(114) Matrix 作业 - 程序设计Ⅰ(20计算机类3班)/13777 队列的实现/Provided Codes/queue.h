#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100

struct queue {
	int front;
	int tail;
	int* elements;
};

void initialize(struct queue* q);

int pop(struct queue* q);

int push(struct queue* q, int number);

int get_size(struct queue* q);

int get_front(struct queue* q);

int empty(struct queue* q);

void list(struct queue* q);

#endif