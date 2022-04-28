#include "queue.h"
Queue::Queue(int m)
{	head=NULL;
	tail=NULL;
	tot_task=0;
	max=m;
}
Queue::~Queue()
{	Node * temp=head;
	while(tot_task)
	{	head=head->next;
		delete temp;
		temp=head;
		tot_task--;
	}
}
bool Queue::isfull() const
{	if(tot_task==max)
		return 1;
	Node * temp=new Node;
	if(temp==NULL)
		return 1;
	delete temp;
	return 0;
}
bool Queue::isempty() const
{	return !tot_task;
}
bool Queue::dequeue(Item & item)
{	if(!tot_task)
	{	cout<<"Queue is empty!"<<endl;
		return 0;
	}
	else if(tot_task==1)
	{	item=head->item;
		delete head;
		head=NULL;
		tot_task--;
		tail=NULL;
	}
	else	
	{	Node *temp=head;
		item=head->item;
		head=head->next;
		delete temp;
		tot_task--;
	}
	return 1;
}
bool Queue::enqueue(Item & item)
{	if(isfull())
		return 0;
	Node * newnode=new Node;
	newnode->next=NULL;
	newnode->item=item;
	if(tot_task)
	{	tail->next=newnode;
		tail=tail->next;
	}
	else
		head=tail=newnode;
	tot_task++;
	return 1;
}
int Queue::count() const
{	return tot_task;
}
void Queue::traverse(void (*pf)(Item item))
{	Node *temp=head;
	while(temp!=NULL)
	{	pf(temp->item);
		temp=temp->next;
	}
}
