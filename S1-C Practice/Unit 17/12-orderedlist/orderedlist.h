#ifndef ORDEREDLIST_H_
#define ORDEREDLIST_H_
#define LIMIT 100000
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct item
{	char title[21];
	char director[21];
	int score;
};
typedef struct item Item;
struct node
{	Item item;
	struct node * next;
};
typedef struct node Node;
struct list
{	Node *head;
	int count;
};
typedef struct list List;
bool InitializeList(List * plist);
bool ListIsFull(List * plist);
bool ListIsEmpty(List * plist);
bool AddItem(List * plist,Item item);
bool DeleteItem(List * plist,Item * pitem);
bool SeekItem(List * plist,Item * pitem);
int ListItemCount(List * plist);
void Traverse(List *plist,void (*pfunc)(Item item));
bool EmptyList(List * plist);
#endif
