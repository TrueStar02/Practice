#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>
using namespace std;
struct Item
{	string task;
	int time;
};
struct Node
{	Item item;
	Node * next;
};
class Queue
{	private:
		Node * head;
		Node * tail;
		int tot_task;
	public:
		Queue();
		~Queue();
		bool isfull() const;
		bool isempty() const;
		bool dequeue(Item & item);
		bool enqueue(Item & item);
		int count() const;
		void traverse(void (*pf)(Item item));
};
#endif
