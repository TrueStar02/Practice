#ifndef CYCLELIST_H_
#define CYCLELIST_H_
#include<iostream>
#include<sstream>
#include<stdexcept>
using namespace std;
template<class K>
class bad_key:public logic_error
{	private:
		K key;
	public:
		bad_key(K k):key(k),logic_error("Cannot find the key "){}
		string what();
};
template<class K,class V>
class CList
{	private:
		class Node
		{	public:
				Node * prior;
				K key;
				V value;
				Node * next;
				Node(K k,V v,Node * p=NULL,Node * n=NULL):key(k),value(v),prior(p),next(n){}
		};
		Node * head;
		int _size;
		bool Find(K k,Node ** pnode);
	public:
		CList();
		CList(const CList & cl);
		CList(CList && cl);
		~CList();
		CList & operator=(const CList & cl);
		CList & operator=(CList && cl);
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
bool CList<K,V>::Find(K k,Node ** pnode)
{	Node * temp=head;
	while(temp->next!=head)
	{	if(temp->next->key>k)
		{	*pnode=temp;
			return 0;
		}
		else if(temp->next->key==k)
		{	*pnode=temp->next;
			return 1;
		}
		temp=temp->next;
	}
	*pnode=temp;
	return 0;
}
template<class K,class V>
CList<K,V>::CList()
{	K k;
	V v;
	head=new Node(k,v);
	head->prior=head;
	head->next=head;
	_size=0;
}
template<class K,class V>
CList<K,V>::CList(const CList & cl)
{	K k;
	V v;
	_size=cl._size;
	head=new Node(k,v);
	Node * temp=cl.head;
	Node * ntemp=head;
	while(temp->next!=cl.head)
	{	ntemp->next=new Node(temp->next->key,temp->next->value,ntemp);
		temp=temp->next;
		ntemp=ntemp->next;
	}
	ntemp->next=head;
	head->prior=ntemp;
}
template<class K,class V>
CList<K,V>::CList(CList && cl)
{	_size=cl._size;
	head=cl.head;
	cl.head=NULL;
}
template<class K,class V>
CList<K,V>::~CList()
{	clear();
	delete head;
}
template<class K,class V>
CList<K,V> & CList<K,V>::operator=(const CList & cl)
{	if(this==&cl)
		return *this;
	clear();
	_size=cl._size;
	Node * temp=cl.head;
	Node * ntemp=head;
	while(temp->next!=cl.head)
	{	ntemp->next=new Node(temp->next->key,temp->next->value,ntemp);
		temp=temp->next;
		ntemp=ntemp->next;
	}
	ntemp->next=head;
	head->prior=ntemp;
	return *this;
}
template<class K,class V>
CList<K,V> & CList<K,V>::operator=(CList && cl)
{	clear();
	_size=cl.size;
	head=cl.head;
	cl.head=NULL;
}
template<class K,class V>
bool CList<K,V>::insert(K k,V v)
{	Node * ins;
	if(!Find(k,&ins))
	{	Node * newnode=new Node(k,v,ins,ins->next);
		ins->next->prior=newnode;
		ins->next=newnode;
		_size++;
		return 1;
	}
	else
		return 0;
}
template<class K,class V>
bool CList<K,V>::erase(K k)
{	Node * era;
	if(Find(k,&era))
	{	era->prior->next=era->next;
		era->next->prior=era->prior;
		delete era;
		_size--;
		return 1;
	}
	else
		return 0;
}
template<class K,class V>
bool CList<K,V>::contains(K k)
{	Node * con;
	return Find(k,&con);
}
template<class K,class V>
V CList<K,V>::operator[](K k) const
{	Node * temp;
	if(Find(k,&temp))
		return temp->value;
	else
		throw bad_key<K>(k);
}
template<class K,class V>
V & CList<K,V>::operator[](K k)
{	Node * temp;
	if(Find(k,&temp))
		return temp->value;
	else
		throw bad_key<K>(k);
}
template<class K,class V>
void CList<K,V>::clear()
{	Node * temp1=head->next;
	Node * temp2=head->next;
	while(temp2->next!=head)
	{	temp1=temp1->next;
		delete temp2;
		temp2=temp1;
	}
	if(temp1!=head)
		delete temp1;
	head->next=head;
	head->prior=head;
	_size=0;
}
template<class K,class V>
void CList<K,V>::PrintAll(bool i) const
{	Node * temp;
	if(i)
	{	temp=head->prior;
		while(temp!=head)
		{	cout<<temp->key<<"   "<<temp->value<<endl;
			temp=temp->prior;
		}
	}
	else
	{	temp=head->next;
		while(temp!=head)
		{	cout<<temp->key<<"   "<<temp->value<<endl;
			temp=temp->next;
		}
	}
}
#endif
