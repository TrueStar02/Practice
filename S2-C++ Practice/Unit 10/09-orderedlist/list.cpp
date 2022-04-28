#include "list.h"
List::List()
{	details=0;
	head=NULL;
}
List::~List()
{	Node * temp=head;
	while(details)
	{	head=head->next;
		delete temp;
		temp=head;
		details--;
	}
}
bool List::add(Item & item)
{	Node *newnode=new Node;
	if(newnode==NULL)
		return 0;
	newnode->item=item;
	newnode->next=NULL;
	if(!details)
		head=newnode;
	else if(comp(item,head->item)<0)
	{	newnode->next=head;
		head=newnode;
	}
	else if(comp(item,head->item)==0)
	{	cout<<"Invalid";
		delete newnode;
		return 0;
	}
	else
	{	Node * temp=head;
		while(((temp->next)!=NULL)&&(comp(item,temp->next->item)>0))
			temp=temp->next;
		if(((temp->next)!=NULL)&&comp(item,temp->next->item)==0)  //Caution!
		{	cout<<"Invalid";
			delete newnode;
			return 0;
		}
		else
		{	newnode->next=temp->next;
			temp->next=newnode;
		}
	}
	details++;
	return 1;
}
bool List::search(Item & item)
{	Node * temp=head;
	while(temp!=NULL&&comp(item,temp->item)>0)
		temp=temp->next;
	if(temp==NULL||comp(item,temp->item))
		return 0;
	else
		return 1;
}
bool List::kill(Item & item)
{	Node * temp=head;
	if(details==0)
		return 0;
	else if(!comp(item,head->item))
	{	
		if(details==1)
		{	delete head;
			head=NULL;
		}
		else
		{	head=head->next;
			delete temp;
		}
	}
	else
	{	while(temp->next!=NULL&&comp(item,temp->next->item)>0)
			temp=temp->next;
		if((temp->next)==NULL||comp(item,temp->next->item))
			return 0;
		else
		{	Node * del=temp->next;
			temp->next=temp->next->next;
			delete del;
		}
	}
	details--;
	return 1;
}
int List::count(void)
{	return details;
}
void List::traverse(void (*pf)(Item item))
{	cout<<"********************Start********************\n";
	Node * temp=head;
	while(temp!=NULL)
	{	pf(temp->item);
		temp=temp->next;
	}
	cout<<"*********************End*********************\n";
}
bool List::isfull(void)
{	Node * temp=new Node;
	if(temp==NULL)
		return 1;
	delete temp;
	return 0;
}
bool List::isempty(void)
{	return !details;
}
int List::comp(Item i1,Item i2)
{	int val=0;
	if(i1.score>i2.score)
		val=2;
	else if(i1.score<i2.score)
		val=-2;
	else if(i1.name>i2.name)
		val=1;
	else if(i1.name<i2.name)
		val=-1;
	return val;
}
