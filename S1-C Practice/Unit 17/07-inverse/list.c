#include<stdio.h>
#include<stdlib.h>
#include "list.h"
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
void EmptyList(List *plist)
{	Node *ptemp;
	while(*plist!=NULL)
	{	ptemp=(*plist)->next;
		free(*plist);
		*plist=ptemp;
	}
}
