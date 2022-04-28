#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>
using namespace std;
struct Item
{	string task;
	int time;
};
class Queue
{	private:
		class Node
		{	public:
				Item item;
				Node * next;
				Node():next(NULL){Item i;item=i;}
				Node(const Item & i):item(i),next(NULL){}
		};
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
