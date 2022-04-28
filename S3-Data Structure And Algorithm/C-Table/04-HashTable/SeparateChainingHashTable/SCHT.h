#ifndef SCHT_H_
#define SCHT_H_
#include<iostream>
#include<stdexcept>
#include<sstream>
using namespace std;
class bad_key:public logic_error
{	private:
		int key;
	public:
		bad_key(int k):key(k),logic_error("Haven't found the key "){}
		virtual string what();		
};
template<class V,int n=10>
class SCHT
{	private:
		class Node
		{	public:	
				int key;
				V value;
				Node * next;
				Node(int k,V v,Node * nd=NULL):key(k),value(v),next(nd){}
		};
		Node * ht[n];
		int _size;
		int Hash(int x){return (x/1000+x%1000)%n;}
		void print(ostream & os,Node * detail){os<<detail->key<<" "<<detail->value<<endl;}
	public:
		SCHT();
		SCHT(const SCHT & s);
		SCHT(SCHT && s);
		~SCHT(){clear();}
		SCHT & operator=(const SCHT & s);
		SCHT & operator=(SCHT && s);
		bool insert(int k,V v);
		bool erase(int k);
		bool contains(int k);
		V operator[](int k) const;
		V & operator[](int k);
		void showall(ostream & os);
		void clear(void);
		bool empty(void) const{return !_size;}
		bool size(void) const{return _size;}
};
string bad_key::what()
{	ostringstream strout;
	strout<<logic_error::what()<<key<<"!";
	return strout.str();
}
template<class V,int n>
SCHT<V,n>::SCHT()
{	_size=0;
	int x;
	for(x=0;x<n;x++)
		ht[x]=NULL;
}
template<class V,int n>
SCHT<V,n>::SCHT(const SCHT & s)
{	_size=s._size;
	int x;
	Node * temp;
	Node * ntemp;
	for(x=0;x<n;x++)
	{	if(s.ht[x]==NULL)
			ht[x]=NULL;
		else
		{	ht[x]=new Node(s.ht[x]->key,s.ht[x]->value);
			temp=s.ht[x];
			ntemp=ht[x];
			while(temp->next!=NULL)
			{	ntemp->next=new Node(temp->next->key,temp->next->value);
				temp=temp->next;
				ntemp=ntemp->next;
			}
		}
	}
}
template<class V,int n>
SCHT<V,n>::SCHT(SCHT && s)
{	_size=s.size;
	int x;
	for(x=0;x<n;x++)
	{	ht[x]=s.ht[x];
		s.ht[x]=NULL;
	}
}
template<class V,int n>
SCHT<V,n> & SCHT<V,n>::operator=(const SCHT & s)
{	if(&s==this)
		return *this;
	clear();
	_size=s._size;
	int x;
	Node * temp;
	Node * ntemp;
	for(x=0;x<n;x++)
	{	if(s.ht[x]==NULL)
			ht[x]=NULL;
		else
		{	ht[x]=new Node(s.ht[x]->key,s.ht[x]->value);
			temp=s.ht[x];
			ntemp=ht[x];
			while(temp->next!=NULL)
			{	ntemp->next=new Node(temp->next->key,temp->next->value);
				temp=temp->next;
				ntemp=ntemp->next;
			}
		}
	}
	return *this;
}
template<class V,int n>
SCHT<V,n> & SCHT<V,n>::operator=(SCHT && s)
{	clear();
	_size=s.size;
	int x;
	for(x=0;x<n;x++)
	{	ht[x]=s.ht[x];
		s.ht[x]=NULL;
	}
	return *this;
}
template<class V,int n>
bool SCHT<V,n>::insert(int k,V v)
{	int index=Hash(k);
	if(ht[index]==NULL)
	{	ht[index]=new Node(k,v);
		_size++;
		return 1;
	}
	Node * temp=ht[index];
	if(temp->key==k)
		return 0;
	while(temp->next!=NULL)
	{	if(temp->next->key==k)
			return 0;
		temp=temp->next;
	}
	temp->next=new Node(k,v);
	_size++;
	return 1;
}
template<class V,int n>
bool SCHT<V,n>::erase(int k)
{	int index=Hash(k);
	if(ht[index]==NULL)
		return 0;
	Node * temp=ht[index];
	Node * temp2;
	if(ht[index]->key==k)
	{	ht[index]=ht[index]->next;
		delete temp;
		_size--;
		return 1;
	}
	while(temp->next!=NULL)
	{	if(temp->next->key==k)
		{	temp2=temp->next;
			temp->next=temp->next->next;
			delete temp2;
			_size--;
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}
template<class V,int n>
bool SCHT<V,n>::contains(int k)
{	int index=Hash(k);
	if(ht[index]==NULL)
		return 0;
	Node * temp=ht[index];
	if(ht[index]->key==k)
		return 1;
	while(temp->next!=NULL)
	{	if(temp->next->key==k)
			return 1;
		temp=temp->next;
	}
	return 0;
}
template<class V,int n>
V SCHT<V,n>::operator[](int k) const
{	int index=Hash(k);
	if(ht[index]=NULL)
		throw bad_key(k);
	Node * temp=ht[index];
	if(ht[index]->key==k)
		return ht[index]->value;
	while(temp->next!=NULL)
	{	if(temp->next->key==k)
			return temp->next->value;
		temp=temp->next;
	}
	throw bad_key(k);
}
template<class V,int n>
V & SCHT<V,n>::operator[](int k)
{	int index=Hash(k);
	if(ht[index]==NULL)
		throw bad_key(k);
	Node * temp=ht[index];
	if(ht[index]->key==k)
		return ht[index]->value;
	while(temp->next!=NULL)
	{	if(temp->next->key==k)
			return temp->next->value;
		temp=temp->next;
	}
	throw bad_key(k);
}
template<class V,int n>
void SCHT<V,n>::showall(ostream & os)
{	int x,count;
	Node * temp;
	for(x=0;x<n;x++)
	{	os<<"Hash Value:"<<x<<endl;
		count=0;
		if(ht[x]==NULL)
			os<<"No data!\n";
		else
		{	print(os,ht[x]);
			count++;
			temp=ht[x];
			while(temp->next!=NULL)
			{	print(os,temp->next);
				count++;
				temp=temp->next;
			}
			os<<"Elements:"<<count<<endl<<endl;
		}
	}
}
template<class V,int n>
void SCHT<V,n>::clear(void)
{	int x;
	Node * temp;
	for(x=0;x<n;x++)
	{	temp=ht[x];
		while(temp!=NULL)
		{	ht[x]=ht[x]->next;
			delete temp;
			temp=ht[x];
		}
	}
	_size=0;
}
#endif
