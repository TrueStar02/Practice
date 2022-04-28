#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
struct film
{	char title[51];
	int rating;
};
typedef struct film Item;
struct node
{	Item item;
	struct node *next;
};
typedef struct node Node;
typedef Node * List;
void InitializeList(List *plist);
bool ListIsFull(List *plist);
bool ListIsEmpty(List *plist);
unsigned int ListItemCount(const List *plist);
bool AddItem(Item item,List *plist);
bool DeleteItem(Item *item,List *plist);
bool SearchItem(Item *item,List *plist);
void Traverse(List *plist,void(*pfunc)(Item item));
void EmptyList(List *plist);
#endif
