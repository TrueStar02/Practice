#include "orderedlist.h"
struct pair
{	Node * parent;
	Node * child;
};
typedef struct pair Pair;
static Pair Search(List *plist,Item item);
static bool MakeNode(Item item,Node * pnode);
static int Forward(Item ins,Item item);
bool InitializeList(List * plist)
{	plist->head=NULL;
	plist->count=0;
}
bool ListIsFull(List * plist)
{	if((plist->count)>=LIMIT)
		return 1;
	bool isfull=0;
	Node * temp=(Node *)malloc(sizeof(Node));
	if(temp==NULL)
		isfull++;
	free(temp);
	return isfull;
}
bool ListIsEmpty(List * plist)
{	return !(plist->count);
}
bool AddItem(List * plist,Item item)
{	Node *newnode,*temp=plist->head;
	newnode=(Node *)malloc(sizeof(Node));
	
	newnode->item=item;
	newnode->next=NULL;
	int label;
	if(plist->head==NULL)
	{	plist->head=newnode;
		plist->count++;
		
		return 1;
	}
	if(label=Forward(item,temp->item)&&!label)
	{	plist->head=newnode;
		newnode->next=temp;
		return 1;
	}
	if(label==-1)
		return 0;
	else if(label)
	{	if(temp->next==NULL)
			{	label=0;
				plist->head->next=newnode;
				
				return 1;
			}
		while((label=Forward(item,temp->next->item)&&label==1))
		{	if(temp->next==NULL)
			{	label=0;
				break;
			}
			temp=temp->next;
		}	
		if(!label)
		{	newnode->next=temp->next;
			temp->next=newnode;
		}
		
		else if(label==-1)
			return 0;
	}
	plist->count++;
	
	return 1;
}
bool DeleteItem(List * plist,Item * pitem)
{	Pair temp=Search(plist,*pitem);
	if(temp.child==NULL)
		return 0;
	if(temp.parent==NULL)
	{	plist->head=temp.child->next;
		free(temp.child);	
	}
	else
	{	temp.parent->next=temp.child->next;
		free(temp.child);
	}
	plist->count--;
	return 1;
}
bool SeekItem(List * plist,Item * pitem)
{	Node * temp=plist->head;
	while(temp!=NULL)
	{	if(!strcmp(temp->item.title,pitem->title)||strcmp(temp->item.director,pitem->director))
			break;	
		temp=temp->next;
	}
	if(temp==NULL)
		return 0;
	*pitem=temp->item;
}
int ListItemCount(List * plist)
{	return plist->count;
}
void Traverse(List *plist,void (*pfunc)(Item item))
{	Node *temp=plist->head;
	while(temp!=NULL)
	{	
		pfunc(temp->item);
		temp=temp->next;
	}	
}
bool EmptyList(List * plist)
{	Node *temp=plist->head;
	while(temp!=NULL)
	{	plist->head=plist->head->next;
		free(temp);
		temp=plist->head;
	}
	return 1;
}
static Pair Search(List *plist,Item item)
{	Pair find;
	find.parent=NULL;
	find.child=plist->head;
	while(find.child!=NULL&&(strcmp(find.child->item.title,item.title)||strcmp(find.child->item.director,item.director)))
	{	find.parent=find.child;
		find.child=find.child->next;
	}
	return find;
}
static bool MakeNode(Item item,Node * pnode)
{	
	return 1;
}
static int Forward(Item ins,Item item)
{	int go=0;
	if(ins.score>item.score)
		go=1;
	else if(ins.score==item.score&&strcmp(ins.title,item.title)>0)
		go=1;
	else if(ins.score==item.score&&strcmp(ins.title,item.title)==0&&strcmp(ins.director,item.director)>0)
		go=1;
	else if(ins.score==item.score&&strcmp(ins.title,item.title)==0&&strcmp(ins.director,item.director)==0)
		go=-1;
	return go;
}
