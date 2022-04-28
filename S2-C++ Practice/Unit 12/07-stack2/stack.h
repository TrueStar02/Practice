#ifndef STACK_H_
#define STACK_H_
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
class Stack
{	private:
		Node * head;
		int tot_task;
	public:
		Stack();
		Stack(const Stack & st);
		~Stack();
		Stack & operator=(const Stack & st);
		bool isfull() const;
		bool isempty() const;
		bool pop(Item & item);
		bool push(Item & item);
		int count() const;
		void traverse(void (*pf)(Item item));
};
#endif
