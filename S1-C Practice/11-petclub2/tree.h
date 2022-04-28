#ifndef TREE_H_
#define TREE_H_
#include<stdbool.h>
struct item
{	char petname[31];
	char petkind[6][31];
	int kinds;
};
typedef struct item Item;
struct trnode
{	Item item;
	struct trnode *left;
	struct trnode *right;
};
typedef struct trnode Trnode;
struct tree
{	Trnode *root;
	int items;
	int pets;
};
typedef struct tree Tree;
void InitializeTree(Tree *ptr);
bool TreeIsEmpty(Tree *ptr);
bool TreeIsFull(Tree *ptr);
bool AddItem(Item item,Tree *ptr);
bool DeleteItem(Item *item,Tree *ptr);
bool SearchItem(Item *item,Tree *ptr);
bool Traverse(Tree *ptr,void(*pfunc)(Item item));
void EmptyTree(Tree *ptr);
int TreeItemCount(Tree *ptr);
int TotalCount(Tree *ptr);
#endif
