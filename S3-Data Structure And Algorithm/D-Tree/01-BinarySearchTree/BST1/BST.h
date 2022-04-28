#ifndef BST_H_
#define BST_H_
#include<iostream>
#include<sstream>
using namespace std;
template<class K>
class bad_key:public logic_error
{	private:
		K key;
	public:
		bad_key(K k):key(k),logic_error("Haven't found the key "){}
		virtual string what();		
};
using namespace std;
template<class K,class V>
class BST
{   private:
        class Node
        {    public:
                K key;
                V value;
                Node * left;
                Node * right;
                Node(K k,V v,Node * l=NULL,Node * r=NULL):key(k),value(v),left(l),right(r){}
        };
        class Pair
        {   public:
                Node * first;
                Node * second;
                Pair(Node* f,Node * s):first(f),second(s){}
        };
        Node * root;
        int _size;
        Pair find(K key)const;
        Node * copy(Node * src);
        void delnode(Node ** p);
        void printall(Node * n)const;
        void delall(Node * p);
    public:
        BST();
        BST(const BST & b);
        BST(BST && b);
        ~BST(){clear();}
        BST & operator=(const BST & b);
        BST & operator=(BST && b);
        bool empty()const{return !_size;}
		int size()const{return _size;}
		bool insert(K k,V v);
		bool erase(K k);
		bool contains(K k)const;
		V operator[](K k) const;
		V & operator[](K k);
        V min()const;
        V max()const;
        V floor(K k)const;
        V ceiling(K k)const;
		void ShowAll(void)const{printall(root);}
        void clear(void);
};
template<class K>
string bad_key<K>::what()
{	ostringstream strout;
	strout<<logic_error::what()<<key<<"!";
	return strout.str();
}
template<class K,class V>
typename BST<K,V>::Pair BST<K,V>::find(K k)const
{   Node * parent=NULL;
    Node * child=NULL;
    if(root==NULL)
        return Pair(NULL,NULL);
    child=root;
    while(child!=NULL)
    {   if(k==child->key)
            return Pair (parent,child);
        else if(k>child->key)
        {   parent=child;
            child=child->right;
        }
        else if(k<child->key)
        {   parent=child;
            child=child->left;
        }
    } 
    return Pair(parent,child);
}
template<class K,class V>
typename BST<K,V>::Node * BST<K,V>::copy(Node * src)
{   Node * des=new Node(src->key,src->value);
    if(src->left!=NULL)
        des->left=copy(src->left);
    if(src->right!=NULL)
        des->right=copy(src->right);
    return des;
}
template<class K,class V>
void BST<K,V>::delnode(Node ** p)
{   Node * temp;
    if((*p)->left==NULL)
    {   temp=(*p);
        *p=temp->right;
        delete temp;
    }
    else if((*p)->right==NULL)
    {   temp=(*p);
        *p=temp->left;
        delete temp;
    }
    else
    {   Pair n(*p,(*p)->left);
        while(n.second->right!=NULL)
        {   n.first=n.second;
            n.second=n.second->right;
        }
        (*p)->key=n.second->key;
        (*p)->value=n.second->value;
        if(*p!=n.first)
            n.first->right=n.second->left;    
        else
            (*p)->left=n.second->left;
       delete n.second;
    }
}
template<class K,class V>
void BST<K,V>::printall(Node * n) const
{   if(n!=NULL)
    {   printall(n->left);
        cout<<n->key<<" "<<n->value<<endl;
        printall(n->right);
    }
}
template<class K,class V>
void BST<K,V>::delall(Node * p)
{   Node * temp=p->right;
    if(p->left!=NULL)
        delall(p->left);
    delete p;
    if(temp!=NULL)
        delall(temp);
}
template<class K,class V>
BST<K,V>::BST()
{   root=NULL;
    _size=0;
}
template<class K,class V>
BST<K,V>::BST(const BST & b)
{   if(b.root!=NULL)
       root=copy(b.root);
    else
        root=NULL;
    _size=b._size;
}
template<class K,class V>
BST<K,V>::BST(BST && b)
{   root=b.root;
    b.root=NULL;
    _size=b._size;
}
template<class K,class V>
BST<K,V> & BST<K,V>::operator=(const BST & b)
{   if(&b==this)
        return *this;
    clear();
    if(b.root!=NULL)
       root=copy(b.root);
    else
        root=NULL;
    _size=b._size;
    return *this;
}
template<class K,class V>
BST<K,V> & BST<K,V>::operator=(BST && b)
{   clear();
    root=b.root;
    b.root=NULL;
    _size=b._size;
    return *this;
}
template<class K,class V>
bool BST<K,V>::insert(K k,V v)
{   Pair pos=find(k);
    if(pos.second!=NULL)
        return 0;
    else if(root==NULL)
        root=new Node(k,v);
    else if(k>pos.first->key)
        pos.first->right=new Node(k,v);
    else if(k<pos.first->key)
        pos.first->left=new Node(k,v);
    _size++;
    return 1;
}
template<class K,class V>
bool BST<K,V>::erase(K k)
{   Pair temp=find(k);
    if(temp.second==NULL)
        return 0;
    if(temp.first==NULL)
        delnode(&root);
    else if(temp.first->left==temp.second)
        delnode(&temp.first->left);
    else if(temp.first->right==temp.second)
        delnode(&temp.first->right);
    _size--;
    return 1;
}
template<class K,class V>
bool BST<K,V>::contains(K k) const
{   Pair temp=find(k);
    if(temp.second==NULL)
        return 0;
    return 1;
}
template<class K,class V>
V BST<K,V>::operator[](K k) const
{   Pair temp=find(k);
    if(temp.second==NULL)
        throw bad_key<K>(k);
    return temp.second->value;
}
template<class K,class V>
V & BST<K,V>::operator[](K k)
{   Pair temp=find(k);
    if(temp.second==NULL)
        throw bad_key<K>(k);
    return temp.second->value;
}
template<class K,class V>
V BST<K,V>::min() const
{   if(root==NULL)
        return;
    Node * temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp->value;
}
template<class K,class V>
V BST<K,V>::max() const
{   if(root==NULL)
        return;
    Node * temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp->value;
}
template<class K,class V>
V BST<K,V>::floor(K k) const
{   if(root==NULL)
        throw bad_key<K>(k);
    Node * temp=root;
    Node * fl=NULL;
    while(temp!=NULL)
    {   if(temp->key==k)
            return temp->value;
        else if(temp->key>k)
            temp=temp->left;
        else
        {   fl=temp;
            temp=temp->right;
        }
    }
    if(fl!=NULL)
    	return fl->value;
    else
    	throw bad_key<K>(k);
}
template<class K,class V>
V BST<K,V>::ceiling(K k) const
{   if(root==NULL)
        throw bad_key<K>(k);
    Node * temp=root;
    Node * fl=NULL;
    while(temp!=NULL)
    {   if(temp->key==k)
            return temp->value;
        else if(temp->key<k)
            temp=temp->right;
        else
        {   fl=temp;
            temp=temp->left;
        }
    }
    if(fl!=NULL)
    	return fl->value;
    else
    	throw bad_key<K>(k);
}
template<class K,class V>
void BST<K,V>::clear(void)
{   if(root!=NULL)
        delall(root);
    root=NULL;
    _size=0;
}
#endif