#ifndef BTREE_H_
#define BTREE_H_
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
template<class K>
class bad_key:public logic_error
{	private:
		K key;
	public:
		bad_key(K k):key(k),logic_error("Haven't found the key "){}
		virtual string what();
};
template<class K>
string bad_key<K>::what()
{	ostringstream strout;
	strout<<logic_error::what()<<key<<"!";
	return strout.str();
}
template<class K,class V,int m=3>
class BTree
{   private:
		class Node
		{   public:
				vector<K> key;
				vector<V> value;
				vector<Node *> node;
				Node * parent;
				bool isleaf;
				Node(Node * p=NULL,bool l=0):parent(p),isleaf(l){}
		};
		class Pair
		{   public:
				Node * first;
				Node * second;
				Pair(Node* f,Node * s):first(f),second(s){}
		};
		Node * root;
		int _size;
		int c;
		Pair find(K k,int & index)const;
		bool BinarySearch(Node * p,K k,int & index)const;
		Node * copy(Node * src);
		void addadjust(Node & p);
		bool delnode(Node ** p,K k,int index=-1);
		void delleft(Node **p,K & k,V & v);
		void delright(Node ** p,K & k,V & v);
		void merge(Node & p,int lefti);
		void borrowL(Node & p,int i);
		void borrowR(Node & p,int i);
		void printall(Node * p)const;
		void delall(Node * p);
	public:
		void testl(Node * p)const
		{	queue<Node *> q;
			int x;
			if(p!=NULL)
				q.push(p);
			while(q.size())
			{	for(x=0;x<q.front()->key.size();x++)
					cout<<q.front()->key[x]<<" "<<q.front()->value[x]<<" "<<endl;	
				if(!q.front()->isleaf)
					for(x=0;x<q.front()->node.size();x++)
						q.push(q.front()->node[x]);
				q.pop();
			}
		}
		BTree();
		BTree(const BTree & t);
		BTree(BTree && t);
		~BTree(){clear();}
		BTree & operator=(const BTree & t);
		BTree & operator=(BTree && t);
		bool empty()const{return root==NULL;}
		int size()const{return _size;}
		bool insert(K k,V v);
		bool erase(K k);
		bool contains(K k)const;
		V operator[](K k) const;
		V & operator[](K k);
		V min()const;
		V max()const;
		void ShowAll(void)const{printall(root);}
		void layer(void)const;
		void clear(void);
};
template<class K,class V,int m>
typename BTree<K,V,m>::Pair BTree<K,V,m>::find(K k,int & index)const
{   Pair f(NULL,root);
	while(f.second!=NULL)
	{   if(BinarySearch(f.second,k,index))
			return f;
		else
		{   f.first=f.second;
			if(!f.second->isleaf)
				f.second=f.second->node[index];
			else
				f.second=NULL;
		}
	}
	return f;
}
template<class K,class V,int m>
bool BTree<K,V,m>::BinarySearch(Node * p,K k,int & index)const
{   int beg=0,end=p->key.size()-1,mid;
	while(beg<=end)
	{   mid=(beg+end)/2;
		if(p->key[mid]==k)
		{   index=mid;
			return 1;
		}
		else if(p->key[mid]>k)
			end=mid-1;
		else
			beg=mid+1;
	}
	index=beg;
	return 0;
}
template<class K,class V,int m>
typename BTree<K,V,m>::Node * BTree<K,V,m>::copy(Node * src)
{   Node * newnode=new Node(NULL,src->isleaf);
	int x;
	newnode->key.insert(newnode->key.begin(),src->key.begin(),src->key.end());
	newnode->value.insert(newnode->value.begin(),src->value.begin(),src->value.end());
	for(x=0;x<src->node.size();x++)
	{   newnode->node.push_back(copy(src->node[x]));
		newnode->node[x]->parent=newnode;
	}
	return newnode;
}
template<class K,class V,int m>
void BTree<K,V,m>::addadjust(Node & p)
{	int mid=p.key.size()/2;
	int index,x;
	if(p.parent!=NULL)
	{	BinarySearch(p.parent,p.key[mid],index);
		(p.parent->key).insert(p.parent->key.begin()+index,p.key[mid]);
		(p.parent->value).insert(p.parent->value.begin()+index,p.value[mid]);
		Node * temp=new Node(p.parent,p.isleaf);
		temp->key.insert(temp->key.begin(),p.key.begin()+mid+1,p.key.end());
		temp->value.insert(temp->value.begin(),p.value.begin()+mid+1,p.value.end());
		if(!p.isleaf)
		{	temp->node.insert(temp->node.begin(),p.node.begin()+mid+1,p.node.end());
			for(x=0;x<temp->node.size();x++)
				temp->node[x]->parent=temp;
		}
		p.parent->node.insert(p.parent->node.begin()+index+1,temp);
		p.key.erase(p.key.begin()+mid,p.key.end());
		p.value.erase(p.value.begin()+mid,p.value.end());
		if(!(p.isleaf))
			p.node.erase(p.node.begin()+mid+1,p.node.end());
		if(p.parent->key.size()==m)
			addadjust(*(p.parent));
	}
	else
	{	Node * nroot=new Node(NULL,0);
		nroot->key.insert(nroot->key.begin(),p.key[mid]);
		nroot->value.insert(nroot->value.begin(),p.value[mid]);
		nroot->node.insert(nroot->node.begin(),root);
		Node * temp=new Node(nroot,p.isleaf);
		temp->key.insert(temp->key.begin(),p.key.begin()+mid+1,p.key.end());
		temp->value.insert(temp->value.begin(),p.value.begin()+mid+1,p.value.end());
		if(!(p.isleaf))
		{	temp->node.insert(temp->node.begin(),p.node.begin()+mid+1,p.node.end());
			for(x=0;x<temp->node.size();x++)
				temp->node[x]->parent=temp;
		}
		nroot->node.insert(nroot->node.begin()+1,temp);
		p.key.erase(p.key.begin()+mid,p.key.end());
		p.value.erase(p.value.begin()+mid,p.value.end());
		if(!(p.isleaf))
			p.node.erase(p.node.begin()+mid+1,p.node.end());
		root->parent=nroot;
		root=nroot;
	}
}
template<class K,class V,int m>
bool BTree<K,V,m>::delnode(Node ** p,K k,int index)
{	bool i=1,r;
	if(index==-1)
		i=BinarySearch(*p,k,index);
	if(i)
	{	r=1;
		if((*p)->isleaf)
		{	(*p)->key.erase((*p)->key.begin()+index);
			(*p)->value.erase((*p)->value.begin()+index);
		}
		else if((*p)->node[index]->key.size()>=c)
		{	K k;
			V v;
			delleft(&((*p)->node[index]),k,v);
			(*p)->key[index]=k;
			(*p)->value[index]=v;
		}
		else if((*p)->node[index+1]->key.size()>=c)
		{	K k;
			V v;
			delright(&((*p)->node[index+1]),k,v);
			(*p)->key[index]=k;
			(*p)->value[index]=v;
		}
		else
		{	int lsize=(*p)->node[index]->key.size();
			merge(**p,index);
			delnode(&((*p)->node[index]),k,lsize);
			if((*p)==root&&((*p)->key.empty()))
			{	root=(*p)->node[0];
				delete root->parent;
				root->parent=NULL;
			}					
		}
	}	
	else
	{	if((*p)->isleaf)
			r=0;
		else if((*p)->node[index]->key.size()>=c)
			r=delnode(&((*p)->node[index]),k);		
		else if(index>0&&(*p)->node[index-1]->key.size()>=c)
		{	borrowL(**p,index);
			r=delnode(&((*p)->node[index]),k);
		}
		else if(index+1<(*p)->node.size()&&(*p)->node[index+1]->key.size()>=c)
		{	borrowR(**p,index);
			r=delnode(&((*p)->node[index]),k);
		}
		else
		{	if(index>0)
			{	merge(**p,index-1);
				r=delnode(&((*p)->node[index-1]),k);
			}
			else
			{	merge(**p,index);
				r=delnode(&((*p)->node[index]),k);
			}
			if((*p)==root&&((*p)->key.empty()))
			{	root=(*p)->node[0];
				delete root->parent;
				root->parent=NULL;
			}	
		}
	}
	return r;
}
template<class K,class V,int m>
void BTree<K,V,m>::delleft(Node **p,K & k,V & v)
{	if((*p)->isleaf)
	{	k=*((*p)->key.end()-1);
		v=*((*p)->value.end()-1);
		(*p)->key.erase((*p)->key.end()-1);
		(*p)->value.erase((*p)->value.end()-1);
	}
	else
	{	if((*((*p)->node.end()-1))->key.size()<c)
		{	if((*((*p)->node.end()-2))->key.size()>=c)
				borrowL(**p,(*p)->key.size());
			else
				merge(**p,(*p)->key.size()-1);
			
		}
		delleft(&*((*p)->node.end()-1),k,v);
	}
}
template<class K,class V,int m>
void BTree<K,V,m>::delright(Node ** p,K & k,V & v)
{	if((*p)->isleaf)
	{	k=(*p)->key[0];
		v=(*p)->value[0];
		(*p)->key.erase((*p)->key.begin());
		(*p)->value.erase((*p)->value.begin());
	}
	else 
	{	if((*p)->node[0]->key.size()<c)
		{	if((*p)->node[1]->key.size()>=c)
				borrowR(**p,0);
			else
				merge(**p,0);
		}
		delright(&((*p)->node[0]),k,v);
	}
}
template<class K,class V,int m>
void BTree<K,V,m>::merge(Node & p,int lefti)
{	int x;
	p.node[lefti]->key.insert(p.node[lefti]->key.end(),p.key[lefti]);
	p.node[lefti]->value.insert(p.node[lefti]->value.end(),p.value[lefti]);
	p.node[lefti]->key.insert(p.node[lefti]->key.end(),p.node[lefti+1]->key.begin(),p.node[lefti+1]->key.end());
	p.node[lefti]->value.insert(p.node[lefti]->value.end(),p.node[lefti+1]->value.begin(),p.node[lefti+1]->value.end());
	if(!p.node[lefti]->isleaf)
	{	for(x=0;x<p.node[lefti+1]->node.size();x++)
			p.node[lefti+1]->node[x]->parent=p.node[lefti];
		p.node[lefti]->node.insert(p.node[lefti]->node.end(),p.node[lefti+1]->node.begin(),p.node[lefti+1]->node.end());
	}
	delete p.node[lefti+1];
	p.key.erase(p.key.begin()+lefti);
	p.value.erase(p.value.begin()+lefti);
	p.node.erase(p.node.begin()+lefti+1);
	
}
template<class K,class V,int m>
void BTree<K,V,m>::borrowL(Node & p,int i)
{	p.node[i]->key.insert(p.node[i]->key.begin(),p.key[i-1]);
	p.node[i]->value.insert(p.node[i]->value.begin(),p.value[i-1]);
	if(!p.node[i]->isleaf)
	{	p.node[i]->node.insert(p.node[i]->node.begin(),*(p.node[i-1]->node.end()-1));
		p.node[i]->node[0]->parent=p.node[i];
	}
	p.key[i-1]=*(p.node[i-1]->key.end()-1);
	p.value[i-1]=*(p.node[i-1]->value.end()-1);
	p.node[i-1]->key.erase(p.node[i-1]->key.end()-1);
	p.node[i-1]->value.erase(p.node[i-1]->value.end()-1);
	if(!p.node[i]->isleaf)
		p.node[i-1]->node.erase(p.node[i-1]->node.end()-1);
}
template<class K,class V,int m>
void BTree<K,V,m>::borrowR(Node & p,int i)
{	p.node[i]->key.insert(p.node[i]->key.end(),p.key[i]);
	p.node[i]->value.insert(p.node[i]->value.end(),p.value[i]);
	if(!p.node[i]->isleaf)
	{	p.node[i]->node.insert(p.node[i]->node.end(),*(p.node[i+1]->node.begin()));
		(*(p.node[i]->node.end()-1))->parent=p.node[i];
	}
	p.key[i]=p.node[i+1]->key[0];
	p.value[i]=p.node[i+1]->value[0];
	p.node[i+1]->key.erase(p.node[i+1]->key.begin());
	p.node[i+1]->value.erase(p.node[i+1]->value.begin());
	if(!p.node[i]->isleaf)
		p.node[i+1]->node.erase(p.node[i+1]->node.begin());
}
template<class K,class V,int m>
void BTree<K,V,m>::printall(Node * p)const
{	int x;
	if(p!=NULL)
	{	//testl(p);
		cout<<endl;
		for(x=0;x<p->key.size();x++)
		{	if(!p->isleaf)
				printall(p->node[x]);
			cout<<p->key[x]<<" "<<p->value[x]<<" "<<endl;
		}
		if(!p->isleaf)
			printall(p->node[x]);
	}
}
template<class K,class V,int m>
void BTree<K,V,m>::delall(Node * p)
{	int x;
	if(!p->isleaf)
	{	for(x=0;x<p->node.size();x++)
			delall(p->node[x]);
	}
	delete p;
}
template<class K,class V,int m>
BTree<K,V,m>::BTree()
{	root=NULL;
	_size=0;
	if(m%2==0)
		c=m/2;
	else
		c=(m+1)/2;
}
template<class K,class V,int m>
BTree<K,V,m>::BTree(const BTree & t)
{   if(t.root!=NULL)
		root=copy(t.root);
		root->parent=NULL;
	_size=t._size;
	c=t.c;
}
template<class K,class V,int m>
BTree<K,V,m>::BTree(BTree && t)
{   root=t.root;
	t.root=NULL;
	_size=t._size;
	c=t.c;
}
template<class K,class V,int m>
BTree<K,V,m> & BTree<K,V,m>::operator=(const BTree & t)
{   if(&t==this)
		return *this;
	clear();
	if(t.root!=NULL)
		root=copy(t.root);
		root->parent=NULL;
	_size=t._size;
	return *this;
}
template<class K,class V,int m>
BTree<K,V,m> & BTree<K,V,m>::operator=(BTree && t)
{   clear();
	root=t.root;
	t.root=NULL;
	_size=t._size;
	return *this;
}
template<class K,class V,int m>
bool BTree<K,V,m>::insert(K k,V v)
{	int index;
	Pair f=find(k,index);
	if(f.second!=NULL)
		return 0;
	_size++;
	if(f.first==NULL)
	{	root=new Node(NULL,1);
		root->key.insert(root->key.begin(),k);
		root->value.insert(root->value.begin(),v);
	}
	else
	{	f.first->key.insert(f.first->key.begin()+index,k);
		f.first->value.insert(f.first->value.begin()+index,v);
		if(f.first->key.size()==m)
			addadjust(*f.first);
	}
	return 1;
}
template<class K,class V,int m>
bool BTree<K,V,m>::erase(K k)
{	int index=-1;
	if(root==NULL)
		return 0;
	else
	{	bool i=delnode(&root,k,index);
		if(i)
			_size--;
		return i;
	}
}
template<class K,class V,int m>
bool BTree<K,V,m>::contains(K k)const
{	int index;
	return find(k,index).second!=NULL;
}
template<class K,class V,int m>
V BTree<K,V,m>::operator[](K k) const
{   int index;
	Pair f=find(k,index);
	if(f.second==NULL)
		throw bad_key<K>(k);
	else
		return f.second->value[index];
}
template<class K,class V,int m>
V & BTree<K,V,m>::operator[](K k)
{   int index;
	Pair f=find(k,index);
	if(f.second==NULL)
		throw bad_key<K>(k);
	else
		return f.second->value[index];
}
template<class K,class V,int m>
V BTree<K,V,m>::min()const
{	if(root==NULL)
        return;
	Node * temp=root;
	while(!temp->isleaf)
		temp=temp->node[0];
	return *(temp->value.begin());
}
template<class K,class V,int m>
V BTree<K,V,m>::max()const
{	if(root==NULL)
        return;
	Node * temp=root;
	while(!temp->isleaf)
		temp=temp->node[temp->node.size()-1];
	return *(temp->value.end()-1);
}
template<class K,class V,int m>
void BTree<K,V,m>::layer(void)const
{	queue<Node *> q;
	int x;
	if(root!=NULL)
		q.push(root);
	while(q.size())
	{	for(x=0;x<q.front()->key.size();x++)
			cout<<q.front()->key[x]<<" "<<q.front()->value[x]<<" "<<endl;	
		if(!q.front()->isleaf)
			for(x=0;x<q.front()->node.size();x++)
				q.push(q.front()->node[x]);
		q.pop();
	}
}
template<class K,class V,int m>
void BTree<K,V,m>::clear(void)
{	_size=0;
	if(root!=NULL)
	{	delall(root);
		root=NULL;
	}
}
#endif