#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <iostream>
using namespace std;
template<class T>
class Queue
{	private:
		class Node
		{	public:
				T item;
				Node * next;
				Node():next(NULL){T i;item=i;}
				Node(const T & i):item(i),next(NULL){}
		};
		Node * head;
		Node * tail;
		int num;
	public:
		Queue(){head=NULL;tail=NULL;num=0;}
		Queue(const Queue & q);
		bool isfull() const;
		bool isempty() const{return !num;}
		bool enqueue(T & item);
		bool dequeue(T & item);
		bool count() const{return num;}
		void traverse(void (*pf) (T item));
		Queue & operator=(const Queue & q);
		~Queue();
};
template<class T>
Queue<T>::Queue(const Queue<T> & q)
{	head=NULL;
	tail=NULL;
	num=q.count();
	if(num)
	{	head=new Node;
		head->item=q.head->item;
		head->next=NULL;
		tail=head;
	}
	if(num>2)
	{	int x;
		Node * temp=head;
		Node * qtemp=q.head;
		for(x=2;x<=num;x++)
		{	temp->next=new Node;
			temp=temp->next;
			qtemp=qtemp->next;
			temp->item=qtemp->item;
			temp->next=NULL;
			tail=temp;
		}
	}
}
template<class T>
bool Queue<T>::isfull() const
{	Node * temp=new Node;
	if(temp==NULL)
		return 1;
	else
	{	delete temp;
		return 0;
	}
}
template<class T>
bool Queue<T>::enqueue(T & item)
{	if(!num)
	{	head=new Node(item);
		tail=head;
	}
	else
	{	tail->next=new Node(item);
		tail=tail->next;
	}
	num++;
	return 1;
}
template<class T>
bool Queue<T>::dequeue(T & item)
{	if(!num)
		return 0;
	else if(num==1)
	{	item=head->item;
		delete head;
		head=tail=NULL;
	}
	else
	{	Node * temp=head;
		item=head->item;
		head=head->next;
		delete temp;
	}
	num--;
	return 1;
}
template<class T>
void Queue<T>::traverse(void (*pf) (T item))
{	int x;
	Node * temp=head;
	for(x=1;x<=num;x++)
	{	pf(temp->item);
		temp=temp->next;
	}
}
template<class T>
Queue<T> & Queue<T>::operator=(const Queue & q)
{	if(this==&q)
		return *this;
	else
	{	int x;
		Node * temp=head;
		for(x=1;x<=num;x++)
		{	head=head->next;
			delete temp;
			temp=head;
		}
		head=NULL;
		tail=NULL;
		num=q.count();
		if(num)
		{	head=new Node;
			head->item=q.head->item;
			head->next=NULL;
			tail=head;
		}
		if(num>2)
		{	temp=head;
			Node * qtemp=q.head;
			for(x=2;x<=num;x++)
			{	temp->next=new Node;
				temp=temp->next;
				qtemp=qtemp->next;
				temp->item=qtemp->item;
				temp->next=NULL;
				tail=temp;
			}
		}
		return *this;
	}
}
template<class T>
Queue<T>::~Queue()
{	int x;
	Node * temp=head;
	for(x=1;x<=num;x++)
	{	head=head->next;
		delete temp;
		temp=head;
	}
}
#endif
