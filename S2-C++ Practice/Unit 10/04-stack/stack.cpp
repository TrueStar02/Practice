#include "stack.h"
Stack::Stack()
{	head=NULL;
	tot_task=0;
}
Stack::~Stack()
{	Node * temp=head;
	while(tot_task)
	{	head=head->next;
		delete temp;
		temp=head;
		tot_task--;
	}
}
bool Stack::isfull() const
{	Node * temp=new Node;
	if(temp==NULL)
		return 1;
	delete temp;
	return 0;
}
bool Stack::isempty() const
{	return !tot_task;
}
bool Stack::pop(Item & item)
{	if(!tot_task)
	{	cout<<"Stack is empty!"<<endl;
		return 0;
	}
	else if(tot_task==1)
	{	item=head->item;
		delete head;
		head=NULL;
		tot_task--;
	}
	else	
	{	Node * temp=head;
		while(temp->next->next!=NULL)
			temp=temp->next;
		item=temp->next->item;
		delete temp->next;
		temp->next=NULL;
		tot_task--;
	}
	return 1;
}
bool Stack::push(Item & item)
{	Node * newnode=new Node;
	newnode->next=NULL;
	newnode->item=item;
	if(tot_task)
	{	Node * temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
	else
		head=newnode;
	tot_task++;
	return 1;
}
int Stack::count() const
{	return tot_task;
}
void Stack::traverse(void (*pf)(Item item))
{	Node *temp=head;
	while(temp!=NULL)
	{	pf(temp->item);
		temp=temp->next;
	}
}
