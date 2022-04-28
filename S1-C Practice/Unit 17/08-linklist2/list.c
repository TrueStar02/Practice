#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
struct pair
{	Node *front;
	Node *back;
};
typedef struct pair Pair;
static Pair SeekItem(Item item,List *plist);
void InitializeList(List *plist)
{	*plist=NULL;
}
bool ListIsFull(List *plist)
{	Node *pt;
	bool isfull=0;
	pt=(Node *)malloc(sizeof(Node));
	if(pt==NULL)
		isfull=1;
	free(pt);
	return isfull;
}
bool ListIsEmpty(List *plist)
{	bool isempty=0;
	if(*plist==NULL)
		isempty=1;
	return isempty;
}
unsigned int ListItemCount(const List *plist)
{	unsigned int count=0;
	Node *pnode=*plist;
	while(pnode!=NULL)
	{	count++;
		pnode=pnode->next;
	}
	return count;
}
bool AddItem(Item item,List *plist)
{	Node *pnode;
	
	Node *pnew=(Node *)malloc(sizeof(Node));
	if(pnew==NULL)
		return 0;
	pnew->item=item;
	pnew->next=NULL;
	if(*plist==NULL)
		*plist=pnew;
	else
	{	pnode=*plist;
		while(pnode->next!=NULL)
			pnode=pnode->next;
		pnode->next=pnew;
	}
	return 1;
}
void Traverse(List *plist,void(*pfunc)(Item item))
{	Node *pnode=*plist;
	while(pnode!=NULL)
	{	pfunc(pnode->item);
		pnode=pnode->next;
	}
}
bool DeleteItem(Item *item,List *plist)
{	Pair target=SeekItem(*item,plist);
	if(target.back==NULL)
	{	printf("Can't find the item!\n");
		return 0;
	}
	if(target.front==NULL)
	{	(*plist)=target.back->next;
		free(target.back);
	}
	else
	{	target.front->next=target.back->next;
		free(target.back);
	}
	return 1;
}
bool SearchItem(Item *item,List *plist)
{	Node *pnode;
	if((pnode=SeekItem(*item,plist).back)==NULL)
		return 0;
	else
	{	*item=pnode->item;
		return 1;
	}
}
void EmptyList(List *plist)
{	Node *ptemp;
	while(*plist!=NULL)
	{	ptemp=(*plist)->next;
		free(*plist);
		*plist=ptemp;
	}
}
static Pair SeekItem(Item item,List *plist)
{	Pair temp;
	for(temp.front=NULL,temp.back=*plist;(temp.back!=NULL)&&strcmp(temp.back->item.title,item.title);temp.front=temp.back,temp.back=temp.back->next)
		continue;
	return temp;
}
