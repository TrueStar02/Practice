#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
void InitializeStack(Stack *pst)
{	pst->first=NULL;
	pst->last=NULL;
	pst->items=0;
}
bool StackIsFull(Stack *pst)
{	Node *pnode=(Node *)malloc(sizeof(Node));
	bool isfull=0;
	if(pnode==NULL)
		isfull=1;
	free(pnode);
	return isfull;
}
bool StackIsEmpty(Stack *pst)
{	if(pst->items==0)
		return 1;
	else
		return 0;
}
bool EnStack(Item item,Stack *pst)
{	if(StackIsFull(pst))
		return 0;
	Node *pnode=(Node *)malloc(sizeof(Node));
	pnode->item=item;
	pnode->next=NULL;
	if(pst->items==0)
	{	pst->first=pnode;
		pst->last=pnode;
	}
	else
	{	pst->last->next=pnode;
		pst->last=pnode;
	}
	pst->items++;
	return 1;
}
bool DeStack(Item *item,Stack *pst)
{	if(StackIsEmpty(pst))
		return 0;
	Node *pnode=pst->first;
	if(pst->items==1)
	{	free(pst->first);
		InitializeStack(pst);
	}
	else
	{	while(pnode->next->next!=NULL)
			pnode=pnode->next;
		*item=pnode->next->item;
		pnode->next=NULL;
		pst->last=pnode;
		pst->items--;
	}
	return 1;
}
int StackItemCount(Stack *pst)
{	return pst->items;
}
void EmptyStack(Stack *pst)
{	Item temp;
	while(!StackIsEmpty(pst))
		DeStack(&temp,pst);
}
