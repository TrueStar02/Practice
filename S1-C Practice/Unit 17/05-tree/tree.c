#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"
struct pair
{	Trnode *parent;
	Trnode *child;
};
typedef struct pair Pair;
static Trnode* MakeNode(const Item *pi);
static bool ToLeft(const Item i1,const Item i2);
static bool ToRight(const Item i1,const Item i2);
static void AddNode(Trnode *NewNode,Trnode *root);
static void InOrder(const Trnode *root,void(*pfunc)(Item item));//put a function to every items.
static Pair SeekItem(const Item *pi,const Tree *ptr);//find the item *pi
static void DeleteNode(Trnode **ppnode);
static void DeleteAllNodes(Trnode *pnode);
void InitializeTree(Tree *ptr)
{	ptr->root=NULL;
	ptr->items=0;
}
bool TreeIsEmpty(Tree *ptr)
{	if(ptr->items==0)
		return 1;
	else
		return 0;
}
bool TreeIsFull(Tree *ptr)
{	Trnode *ptrnode=(Trnode *)malloc(sizeof(Trnode));
	bool isfull=0;
	if(ptrnode==NULL)
		isfull=1;
	return isfull;
}
bool AddItem(Item item,Tree *ptr)
{	if(TreeIsFull(ptr))
	{	fprintf(stderr,"The tree is full.\n");
		return 0;
	}
	if(SeekItem(&item,ptr).child!=NULL)
	{	fprintf(stderr,"This item has already existed!\n");
		return 0;
	}
	Trnode *NewNode=MakeNode(&item);
	if(NewNode==NULL)
	{	fprintf(stderr,"Couldn't create a node!\n");
		return 0;
	}
	if(ptr->items==0)
		ptr->root=NewNode;
	else
		AddNode(NewNode,ptr->root);
	ptr->items++;
	return 1;
}
bool DeleteItem(Item *item,Tree *ptr)
{	Pair ppair=SeekItem(item,ptr);
	if(ppair.child==NULL)
	{	printf("Couldn't find this item\n");
		return 0;
	}
	if(ppair.parent==NULL)
		DeleteNode(&ptr->root);
	else if(ppair.parent->left==ppair.child)
		DeleteNode(&ppair.parent->left);
	else
		DeleteNode(&ppair.parent->right);
	ptr->items--;
	return 1;
}
bool SearchItem(Item *item,Tree *ptr)
{	if(SeekItem(item,ptr).child==NULL)
		return 0;
	else
		return 1;
}
bool Traverse(Tree *ptr,void(*pfunc)(Item item))
{	if(ptr!=NULL)
		InOrder(ptr->root,pfunc);
}
void EmptyTree(Tree *ptr)
{	if(ptr!=NULL)
		DeleteAllNodes(ptr->root);
	InitializeTree(ptr);
}
int TreeItemCount(Tree *ptr)
{	return ptr->items;
}
static Trnode* MakeNode(const Item *pi)
{	Trnode *temp=(Trnode *)malloc(sizeof(Trnode));
	temp->item=*pi;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
static bool ToLeft(const Item i1,const Item i2)
{	bool toleft=0;
	if(strcmp(i1.petname,i2.petname)<0)
		toleft=1;
	else if(strcmp(i1.petname,i2.petname)==0&&strcmp(i1.petkind,i2.petkind)<0)
		toleft=1;
	return toleft;
}
static bool ToRight(const Item i1,const Item i2)
{	bool toright=0;
	if(strcmp(i1.petname,i2.petname)>0)
		toright=1;
	else if(strcmp(i1.petname,i2.petname)==0&&strcmp(i1.petkind,i2.petkind)>0)
		toright=1;
	return toright;
}
static void AddNode(Trnode *NewNode,Trnode *root)
{	if(ToLeft(NewNode->item,root->item))
	{	if(root->left==NULL)
			root->left=NewNode;
		else
			AddNode(NewNode,root->left);
	}
	else if(ToRight(NewNode->item,root->item))
	{	if(root->right==NULL)
			root->right=NewNode;
		else
			AddNode(NewNode,root->right);
	}
	else
		fprintf(stderr,"Your Mother Boomed!\n");
}
static void InOrder(const Trnode *root,void(*pfunc)(Item item))
{	if(root!=NULL)
	{	InOrder(root->left,pfunc);
		pfunc(root->item);
		InOrder(root->right,pfunc);
	}	
}
static Pair SeekItem(const Item *pi,const Tree *ptr)
{	Pair result;
	result.parent=NULL;
	result.child=ptr->root;
	while(result.child!=NULL)
	{	if(ToLeft(*pi,(result.child->item)))
		{	result.parent=result.child;
			result.child=result.child->left;
		}
		else if(ToRight(*pi,(result.child->item)))
		{	result.parent=result.child;
			result.child=result.child->right;
		}
		else
			break;
	}
	return result;
}
static void DeleteNode(Trnode **ppnode)
{	Trnode *temp;
	if((*ppnode)->left==NULL)
	{	temp=*ppnode;
		*ppnode=(*ppnode)->right;
		free(temp);
	}
	else if((*ppnode)->right==NULL)
	{	temp=*ppnode;
		*ppnode=(*ppnode)->left;
		free(temp);
	}
	else
	{	for(temp=(*ppnode)->left;temp->right!=NULL;temp=temp->right)
			continue;
		temp->right=(*ppnode)->right;
		temp=(*ppnode);
		*ppnode=(*ppnode)->left;
		free(temp);
	}
}
static void DeleteAllNodes(Trnode *pnode)
{	Trnode *pright;
	if(pnode!=NULL)
	{	pright=pnode->right;
		DeleteAllNodes(pnode->left);
		free(pnode);
		DeleteAllNodes(pright);
	}
}
