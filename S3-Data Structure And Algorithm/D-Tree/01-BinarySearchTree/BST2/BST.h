#ifndef BST_H_
#define BST_H_
#include<iostream>
#include<sstream>
#include<queue>
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
template<class K,class V>
class BST
{   private:
        class Node
        {   public:
                K key;
                V value;
                int size;
                Node * left;
                Node * right;
                Node(K k,V v,int s=1,Node * l=NULL,Node * r=NULL):key(k),value(v),left(l),right(r),size(s){}
        };
        class Pair
        {   public:
                Node * first;
                Node * second;
                Pair(Node* f,Node * s):first(f),second(s){}
        };
        Node * root;
        int getsize(Node * p)const;
        Pair find(K key)const;
        Node * copy(Node * src);
        bool addnode(K k,V v,Node * p);
        bool delnode(K k,Node ** p);
        void printall(Node * n)const;
        void delall(Node * p);
    public:
        BST(){root=NULL;}
        BST(const BST & b);
        BST(BST && b);
        ~BST(){clear();}
        BST & operator=(const BST & b);
        BST & operator=(BST && b);
        bool empty()const{return root==NULL;}
		int size()const{return getsize(root);}
		bool insert(K k,V v);
		bool erase(K k);
		bool contains(K k)const;
		V operator[](K k) const;
		V & operator[](K k);
        V min()const;
        V max()const;
        V floor(K k)const;
        V ceiling(K k)const;
        int rank(K k)const;
		void ShowAll(void)const{printall(root);}
        void layer(void)const;
        void clear(void);
};
template<class K,class V>
int BST<K,V>::getsize(Node * p)const
{   if(p==NULL)
        return 0;
    else 
        return p->size;
}
template<class K,class V>
typename BST<K,V>::Pair BST<K,V>::find(K key)const
{   Node * parent=NULL;
    Node * child=root;
    if(root==NULL)
        return Pair(NULL,NULL);
    while(child!=NULL)
    {   if(key==child->key)
            return Pair (parent,child);
        else if(key>child->key)
        {   parent=child;
            child=child->right;
        }
        else if(key<child->key)
        {   parent=child;
            child=child->left;
        }
    } 
    return Pair(parent,child);
}
template<class K,class V>
typename BST<K,V>::Node * BST<K,V>::copy(Node * src)
{   Node * newnode=new Node(src->key,src->value,src->size);
    if(src->left!=NULL)
        newnode->left=copy(src->left);
    if(src->right!=NULL)
        newnode->right=copy(src->right);
    return newnode;
}
template<class K,class V>
bool BST<K,V>::addnode(K k,V v,Node * p)
{   bool i;
    if(p->key==k)
        i=0;
    else if(p->key>k)
    {   if(p->left==NULL)
        {   p->left=new Node(k,v);
            i=1;
        }
        else
        i=addnode(k,v,p->left);
    }
    else
    {   if(p->right==NULL)
        {   p->right=new Node(k,v);
            i=1;
        }
        else
        i=addnode(k,v,p->right);
    }
    p->size=1+getsize(p->left)+getsize(p->right);
    return i;
}
template<class K,class V>
bool BST<K,V>::delnode(K k,Node ** p)
{   bool i;
    if(k==(*p)->key)
    {   if((*p)->left==NULL)
        {   Node * temp=*p;
            *p=(*p)->right;
            delete temp;
        }
        else if((*p)->right==NULL)
        {   Node * temp=*p;
            *p=(*p)->left;
            delete temp;
        }
        else
        {   Pair f(*p,(*p)->left);
            while(f.second->right!=NULL)
            {   f.second->size--;
                f.first=f.second;
                f.second=f.second->right;
            }
            (*p)->key=f.second->key;
            (*p)->value=f.second->value;
            if((*p)==f.first)
                (*p)->left=f.second->left;
            else
                f.first->right=f.second->left;
            delete f.second;
        }
        i=1;
    }
    else if(k>(*p)->key)
    {   if((*p)->right==NULL)
            i=0;
        else 
            i=delnode(k,&((*p)->right));
    }
    else 
    {   if((*p)->left==NULL)
            i=0;
        else 
            i=delnode(k,&((*p)->left));
    }
    (*p)->size=getsize((*p)->left)+getsize((*p)->right)+1;
    return i;
}
template<class K,class V>
void BST<K,V>::printall(Node * n)const
{   if(n!=NULL)
    {   printall(n->left);
        cout<<n->key<<" "<<n->value<<" "<<"Size:"<<n->size<<endl;
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
BST<K,V>::BST(const BST & b)
{   if(b.root!=NULL)
        root=copy(b.root);
    else
        root=NULL;   
}
template<class K,class V>
BST<K,V>::BST(BST && b)
{   root=b.root;
    b.root=NULL;
}
template<class K,class V>
BST<K,V> & BST<K,V>::operator=(const BST & b)
{   if(this==&b)
        return *this;
    clear();
    if(b.root!=NULL)
        root=copy(b.root);
    else
        root=NULL;   
    return *this;
}
template<class K,class V>
BST<K,V> & BST<K,V>::operator=(BST && b)
{   clear();
    root=b.root;
    b.root=NULL;
}
template<class K,class V>
bool BST<K,V>::insert(K k,V v)
{   if(root==NULL)
    {    root=new Node(k,v);
            return 1;
    }
    else
        return addnode(k,v,root);
}
template<class K,class V>
bool BST<K,V>::erase(K k)
{   if(root==NULL)
        return 0;
    else    
        return delnode(k,&root);
}
template<class K,class V>
bool BST<K,V>::contains(K k)const
{   Pair f=find(k);
    return f.second!=NULL;
}
template<class K,class V>
V BST<K,V>::operator[](K k) const
{   Pair f=find(k);
    if(f.second!=NULL)
        return f.second->value;
    else 
        throw bad_key<K>(k);
}
template<class K,class V>
V & BST<K,V>::operator[](K k)
{   Pair f=find(k);
    if(f.second!=NULL)
        return f.second->value;
    else 
        throw bad_key<K>(k);
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
V BST<K,V>::floor(K k)const
{   Node * temp=root;
    Node * p=NULL;
    while(temp!=NULL)
    {   if(temp->key==k)
            return temp->value;
        else if(temp->key<k)
        {   p=temp;
            temp=temp->right;
        }
        else
            temp=temp->left;
    }
    if(p!=NULL)
        return p->value;
    else
        throw bad_key<K>(k);
}
template<class K,class V>
int BST<K,V>::rank(K k)const
{   Node * temp=root;
    int sum=0;
    while(temp!=NULL)
    {   if(k==temp->key)
        {   sum+=getsize(temp->left)+1;
            break;
        }
        else if(k>temp->key)
        {   sum+=getsize(temp->left)+1;
            temp=temp->right;
        }
        else
            temp=temp->left;
    }
    if(temp==NULL)
        return 0;
    else
        return sum;
}
template<class K,class V>
V BST<K,V>::ceiling(K k)const
{   Node * temp=root;
    Node * p=NULL;
    while(temp!=NULL)
    {   if(temp->key==k)
            return temp->value;
        else if(temp->key>k)
        {   p=temp;
            temp=temp->left;
        }
        else
            temp=temp->right;
    }
    if(p!=NULL)
        return p->value;
    else
        throw bad_key<K>(k);
}
template<class K,class V>
void BST<K,V>::layer(void)const
{   queue<Node *> q;
    if(root!=NULL)
    {   q.push(root);
        while(!q.empty())
        {   cout<<q.front()->key<<" "<<q.front()->value<<" "<<"Size:"<<q.front()->size<<endl;
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
        }
    }
}
template<class K,class V>
void BST<K,V>::clear(void)
{   if(root!=NULL)
        delall(root);
    root=NULL;
    cout<<"Cleared\n";
}
#endif
