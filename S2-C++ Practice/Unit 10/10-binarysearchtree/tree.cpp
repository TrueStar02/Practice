#include "tree.h"
Tree::Tree()
{	root=NULL;
	items=0;
	num=0;
}
Tree::~Tree()
{	if(root!=NULL)
		FreeAll(root);
}
bool Tree::isfull()
{	Trnode *temp=new Trnode;
	if(temp==NULL)
		return 1;
	delete temp;
	return 0;
}
bool Tree::isempty()
{	return !items;
}
bool Tree::add(Item & item)
{	if(root==NULL)
		root=MakeNode(item);
	else
		AddItem(root,item);
	num++;
	return 1;
}
bool Tree::del(Item & item)
{	Pair temp=FindItem(item);
	if(temp.child==NULL)
		return 0;
	else if(temp.child->item.fre>1)
		temp.child->item.fre--;
	else 
	{	if(temp.parent==NULL)
			DeleteNode(&root);
		else if(temp.parent->left==temp.child)
			DeleteNode(&temp.parent->left);
		else
			DeleteNode(&temp.parent->right);
	}
	num--;
	return 1;
}
void Tree::traverse(void (*pf)(Item item))
{	InOrder(root,pf);
}
int Tree::itemcount()
{	return items;
}
int Tree::wordcount()
{	return num;
}
bool Tree::search(Item & item)
{	Pair temp=FindItem(item);
	if(temp.child==NULL)
		return 0;
	else
	{	item=temp.child->item;
		return 1;
	}
}
Pair Tree::FindItem(Item & item)
{	Pair temp={NULL,root};
	while(temp.child!=NULL)
	{	if(item.word==temp.child->item.word)
			break;
		else if(item.word>temp.child->item.word)
		{	temp.parent=temp.child;
			temp.child=temp.child->right;
		}
		else
		{	temp.parent=temp.child;
			temp.child=temp.child->left;
		}
	}
	return temp;
}
void Tree::InOrder(Trnode * pnode,void (*pf)(Item item))
{	if(pnode!=NULL)
	{	InOrder(pnode->left,pf);
		pf(pnode->item);
		InOrder(pnode->right,pf);
	}
}
void Tree::AddItem(Trnode * pnode,Item item)
{	if(pnode->item.word==item.word)
		pnode->item.fre++;
	else if(pnode->item.word>item.word)
	{	if(pnode->left==NULL)
			pnode->left=MakeNode(item);
		else
			AddItem(pnode->left,item);
	}
	else
	{	if(pnode->right==NULL)
			pnode->right=MakeNode(item);
		else
			AddItem(pnode->right,item);
	}
}
Trnode * Tree::MakeNode(Item item)
{	Trnode *newnode=new Trnode;
	newnode->item=item;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
void Tree::DeleteNode(Trnode **ppnode)
{	Trnode * temp;
	if((*ppnode)->left==NULL)
	{	temp=*ppnode;
		*ppnode=(*ppnode)->right;
		delete temp;
	}
	else if((*ppnode)->right==NULL)
	{	temp=*ppnode;
		*ppnode=(*ppnode)->left;
		delete temp;
	}
	else
	{	temp=(*ppnode)->left;
		while(temp->right!=NULL)
			temp=temp->right;
		temp->right=(*ppnode)->right;
		temp=*ppnode;
		*ppnode=(*ppnode)->left;
		delete temp;
	}
}
void Tree::FreeAll(Trnode * pnode)
{	if(pnode!=NULL)
	{	Trnode * temp=pnode->right;
		FreeAll(pnode->left);
		delete pnode;
		FreeAll(temp);
	}
}
