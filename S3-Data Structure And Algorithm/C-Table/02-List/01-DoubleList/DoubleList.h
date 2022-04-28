#ifndef DOUBLELIST_H_
#define DOUBLELIST_H_
#include<stdexcept>
#include<sstream>
#include<iostream>
using namespace std;
template<class K>
class bad_key:public logic_error
{	private:
		K key;
	public:
		bad_key(K k):key(k),logic_error("Haven't found the key "){}
		virtual string what();		
};
template<class K,class V>
class DList
{	private:
		class Node
		{	public:
				Node * prior;
				K key;
				V value;
				Node * next;
				Node(const K & k,const V & v,Node * p=NULL,Node * n=NULL):key(k),value(v),prior(p),next(n){}
		};
		Node * head;
		Node * tail;
		int _size;
		bool Find(K k,Node ** pnode);
	public:
		DList();
		DList(const DList & d);
		DList(DList && d);
		~DList();
		DList & operator=(const DList & d);
		DList & operator=(DList && d);
		bool insert(K k,V v);
		bool erase(K k);
		bool contains(K k);
		V operator[](K k) const;
		V & operator[](K k);
		void clear();
		void PrintAll(bool i) const;
		bool empty() const{return !_size;}
		int size() const{return _size;}
};
template<class K>
string bad_key<K>::what()
{	ostringstream strout;
	strout<<logic_error::what()<<key<<"!";
	return strout.str();
}
template<class K,class V>
bool DList<K,V>::Find(K k,Node ** pnode)
{	Node *temp=head;
	while(temp->next!=NULL)
	{	if(temp->next->key==k)
		{	*pnode=temp->next;
			return 1;
		}
		else if(temp->next->key>k)
		{	*pnode=temp;
			return 0;
		}
		temp=temp->next;
	}
	*pnode=temp;
	return 0;
}
template<class K,class V>
DList<K,V>::DList()
{	K k;
	V v;
	head=new Node(k,v);
	tail=head;
	_size=0;
}
template<class K,class V>
DList<K,V>::DList(const DList<K,V> & d)
{	K k;
	V v;
	_size=d._size;
	head=new Node(k,v);
	tail=head;
	Node * temp=d.head;
	Node * ntemp=head;
	while(temp->next!=NULL)
	{	ntemp->next=new Node(temp->next->key,temp->next->value,ntemp);
		temp=temp->next;
		ntemp=ntemp->next;
	}
	tail=temp;
}
template<class K,class V>
DList<K,V>::DList(DList<K,V> && d)
{	_size=d._size;
	head=d.head;
	tail=d.tail;
	d.head=NULL;
	d.tail=NULL;
}
template<class K,class V>
DList<K,V>::~DList()
{	Node * temp=head;
	while(temp->next!=NULL)
	{	head=head->next;
		delete temp;
		temp=head;
	}
	delete temp;
}
template<class K,class V>
DList<K,V> & DList<K,V>::operator=(const DList<K,V> & d)
{	if(this==&d)
		return *this;
	clear();
	_size=d._size;
	Node * temp=d.head;//WARNING
	Node * ntemp=head;
	while(temp->next!=NULL)
	{	ntemp->next=new Node(temp->next->key,temp->next->value,ntemp);
		temp=temp->next;
		ntemp=ntemp->next;
	}
	tail=temp;
	return *this;
}
template<class K,class V>
DList<K,V> & DList<K,V>::operator=(DList<K,V> && d)
{	clear();
	delete head;
	_size=d._size;
	head=d.head;
	tail=d.tail;
	d.head=NULL;
	d.tail=NULL;
	return *this;
}
template<class K,class V>
bool DList<K,V>::insert(K k,V v)
{	Node *p;
	if(Find(k,&p))
		return 0;
	Node * newnode=new Node(k,v,p,p->next);
	if(p->next!=NULL)
		p->next->prior=newnode;
	else
		tail=newnode;
	p->next=newnode;
	_size++;
	return 1;
}
template<class K,class V>
bool DList<K,V>::erase(K k)
{	Node *p;
	if(!Find(k,&p))
		return 0;
	p->prior->next=p->next;
	if(p->next!=NULL)
		p->next->prior=p->prior;
	else
		tail=p->prior;
	_size--;
	return 1;
}
template<class K,class V>
bool DList<K,V>::contains(K k)
{	Node * p;
	return Find(k,&p);
}	
template<class K,class V>
V DList<K,V>::operator[](K k) const
{	Node * p;
	if(Find(k,&p))
		return p->value;
	else
		throw bad_key<K>(k);
}
template<class K,class V>
V & DList<K,V>::operator[](K k)
{	Node * p;
	if(Find(k,&p))
		return p->value;
	else
		throw bad_key<K>(k);
}
template<class K,class V>
void DList<K,V>::clear()
{	if(head->next!=NULL)
	{	Node * temp1=head->next;
		Node * temp2=head->next;
		while(temp1!=NULL)
		{	temp1=temp1->next;
			delete temp2;
			temp2=temp1;
		}
		head->next=NULL;
		tail=head;
	}
	_size=0;
}
template<class K,class V>
void DList<K,V>::PrintAll(bool i) const
{	Node * temp;
	if(i==0)
	{	temp=head->next;
		while(temp!=NULL)
		{	cout<<temp->key<<"   "<<temp->value<<endl;
			temp=temp->next;
		}
	}
	else
	{	temp=tail;
		while(temp->prior!=NULL)
		{	cout<<temp->key<<"   "<<temp->value<<endl;
			temp=temp->prior;
		}
	}
}
#endif
