#ifndef LIST_H_
#define LIST_H_
#include<iostream>
using namespace std;
struct Item
{	string name;
	double score;	
};
struct Node
{	Item item;
	Node * next;
};
class List
{	private:
		Node * head;
		int details;
		int comp(Item i1,Item i2);
	public:
		List();
		~List();
		bool add(Item & item);
		bool search(Item & item);
		bool kill(Item & item);
		int count(void);
		void traverse(void (*pf)(Item item));
		bool isfull(void);
		bool isempty(void);
};
#endif
