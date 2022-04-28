#ifndef TREE_H_
#define TREE_H_
#include<iostream>
#include<cctype>
using namespace std;
struct Item
{	string word;
	int fre;
};
struct Trnode
{	Item item;
	Trnode * left;
	Trnode * right;
};
struct Pair
{	Trnode * parent;
	Trnode * child;
};
class Tree
{	private:
		Trnode * root;
		int items;
		int num;
		Pair FindItem(Item & item);
		void InOrder(Trnode * pnode,void (*pf)(Item item));
		void AddItem(Trnode * pnode,Item item);
		Trnode * MakeNode(Item item);
		void DeleteNode(Trnode **ppnode);
		void FreeAll(Trnode * pnode);
	public:
		Tree();
		~Tree();
		bool isfull();
		bool isempty();
		bool add(Item & item);
		bool del(Item & item);
		void traverse(void (*pf)(Item item));
		int itemcount();
		int wordcount();
		bool search(Item & item);
};
#endif
