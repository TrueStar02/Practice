#ifndef AVLTREE_H_
#define AVLTREE_H_
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
class AVLTree
{   private:
        class Node
        {   public:
                K key;
                V value;
                Node * parent;
                Node * left;
                Node * right;
                int size;
                int height;
                Node(K k,V v,int s=1,int h=1,Node * p=NULL,Node * l=NULL,Node * r=NULL):key(k),value(v),size(s),height(h),parent(p),left(l),right(r){}
        };
        class Pair
        {   public:
                Node * first;
                Node * second;
                Pair(Node* f,Node * s):first(f),second(s){}
        };
        Node * root;
        int getsize(Node * p)const;
        int getheight(Node * p)const;
        Pair find(K key)const;
        Node * copy(Node * src);
        void delnode(Node ** p);
        void adjust(Node ** p);
        void LL(Node ** p);
        void LR(Node ** p);
        void RR(Node ** p);
        void RL(Node ** p);
        void leftrotate(Node & p);
        void rightrotate(Node & p);
        void printall(Node * n)const;
        void delall(Node * p);
    public:
        AVLTree(){root=NULL;}
        AVLTree(const AVLTree & t);
        AVLTree(AVLTree && t);
        ~AVLTree(){clear();}
        AVLTree & operator=(const AVLTree & t);
        AVLTree & operator=(AVLTree && t);
        bool empty()const{return root==NULL;}
		int size()const{return getsize(root);}
		bool insert(K k,V v);
		bool erase(K k);
		bool contains(K k)const{return find(k).second!=NULL;}
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
int AVLTree<K,V>::getsize(Node * p)const
{   if(p==NULL)
        return 0;
    else
        return p->size;
}
template<class K,class V>
int AVLTree<K,V>::getheight(Node * p)const
{   if(p==NULL)
        return 0;
    else
        return p->height;
}
template<class K,class V>
typename AVLTree<K,V>::Pair AVLTree<K,V>::find(K key)const
{   Pair temp(NULL,root);
    while(temp.second!=NULL)
    {   if(key==temp.second->key)
            break;
        temp.first=temp.second;
        if(key>temp.second->key)
            temp.second=temp.second->right;
        else
            temp.second=temp.second->left;    
    }
    return temp;
}
template<class K,class V>
typename AVLTree<K,V>::Node * AVLTree<K,V>::copy(Node * src)
{   Node * newnode=new Node(src->key,src->value,src->size,src->height);
    if(src->left!=NULL)
    {   newnode->left=copy(src->left);
        newnode->left->parent=newnode;
    }
      if(src->right!=NULL)
    {   newnode->right=copy(src->right);
        newnode->right->parent=newnode;
    }
    return newnode;
}
template<class K,class V>
void AVLTree<K,V>::delnode(Node ** p)
{   if((*p)->left==NULL)
    {   Node * temp=(*p);
        if((*p)->right!=NULL)
            (*p)->right->parent=(*p)->parent;
        (*p)=(*p)->right;
        if(temp->parent!=NULL)
            adjust(&(temp->parent));
        delete temp;
    }
    else if((*p)->right==NULL)
    {   Node * temp=(*p);
        (*p)->left->parent=(*p)->parent;
        (*p)=(*p)->left;
        if(temp->parent!=NULL)
            adjust(&(temp->parent));
        delete temp;
    }
    else
    {   Pair f(*p,(*p)->left);
        while(f.second->right!=NULL)
        {   f.first=f.second;
            f.second=f.second->right;
        }
        (*p)->key=f.second->key;
        (*p)->value=f.second->value;
        if(f.second->left!=NULL)
            f.second->left->parent=f.first;
        if(f.first==(*p))
            (*p)->left=f.second->left;
        else
            f.first->right=f.second->left;
        adjust(&(f.first));
        delete f.second;
    }
    
}
template<class K,class V>
void AVLTree<K,V>::adjust(Node ** p)
{   Node * temp=(*p);
    while(temp!=NULL)
    {   if(getheight(temp->left)-getheight(temp->right)>1)
        {   if(getheight(temp->left->left)>getheight(temp->left->right))
                LL(&(temp->left->parent));
            else
                LR(&(temp->left->parent));  
        }
        else if(getheight(temp->left)-getheight(temp->right)<-1)
        {   if(getheight(temp->right->right)>getheight(temp->right->left))
                RR(&(temp->right->parent));
            else
                RL(&(temp->right->parent));  
        }
        temp->size=1+getsize(temp->left)+getsize(temp->right);
        if(getheight(temp->left)>=getheight(temp->right)) 
            temp->height=1+getheight(temp->left);
        else
            temp->height=1+getheight(temp->right); 
        temp=temp->parent;
    }
}
template<class K,class V>
void AVLTree<K,V>::LL(Node ** p)
{   rightrotate(**p);}
template<class K,class V>
void AVLTree<K,V>::LR(Node ** p)
{   leftrotate(*((*p)->left));
    rightrotate(*((*p)->parent));
}
template<class K,class V>
void AVLTree<K,V>::RR(Node ** p)
{   leftrotate(**p);}
template<class K,class V>
void AVLTree<K,V>::RL(Node ** p)
{   rightrotate(*((*p)->right));
    leftrotate(*((*p)->parent));
}
template<class K,class V>
void AVLTree<K,V>::leftrotate(Node & p)
{   Node * temp=p.right;
    p.right=p.right->left;
    if(temp->left!=NULL)
        temp->left->parent=&p;
    temp->parent=p.parent;
    if(p.parent==NULL)
        root=temp;
    else if(p.parent->left==&p)
        p.parent->left=temp;
    else
        p.parent->right=temp;
    temp->left=&p;
    p.parent=temp;
    p.size=1+getsize(p.left)+getsize(p.right);
    p.parent->size=1+getsize(p.parent->left)+getsize(p.parent->right);
    if(getheight(p.left)>=getheight(p.right))
        p.height=1+getheight(p.left);
    else
        p.height=1+getheight(p.right);
    if(getheight(p.parent->left)>=getheight(p.parent->right))
        p.parent->height=1+getheight(p.parent->left);
    else
        p.parent->height=1+getheight(p.parent->right);
}
template<class K,class V>
void AVLTree<K,V>::rightrotate(Node & p)
{   Node * temp=p.left;
    p.left=p.left->right;
    if(temp->right!=NULL)
        temp->right->parent=&p;
    temp->parent=p.parent;
    if(p.parent==NULL)
        root=temp;
    else if(p.parent->left==&p)
        p.parent->left=temp;
    else
        p.parent->right=temp;
    temp->right=&p;
    p.parent=temp;
    p.size=1+getsize(p.left)+getsize(p.right);
    p.parent->size=1+getsize(p.parent->left)+getsize(p.parent->right);
    if(getheight(p.left)>=getheight(p.right))
        p.height=1+getheight(p.left);
    else
        p.height=1+getheight(p.right);
    if(getheight(p.parent->left)>=getheight(p.parent->right))
        p.parent->height=1+getheight(p.parent->left);
    else
        p.parent->height=1+getheight(p.parent->right);
}
template<class K,class V>
void AVLTree<K,V>::printall(Node * n)const
{   if(n!=NULL)
    {   printall(n->left);
        cout<<n->key<<" "<<n->value<<" "<<"Size:"<<n->size<<endl;
        printall(n->right);
    }
}
template<class K,class V>
void AVLTree<K,V>::delall(Node * p)
{   Node * temp=p->right;
    if(p->left!=NULL)
        delall(p->left);
    delete p;
    if(temp!=NULL)
        delall(temp);
}
template<class K,class V>
AVLTree<K,V>::AVLTree(const AVLTree & t)
{   if(t.root!=NULL)
    {   root=copy(t.root);
        root->parent=NULL;
    }
    else
        root=NULL;
}
template<class K,class V>
AVLTree<K,V>::AVLTree(AVLTree && t)
{   root=t.root;
    t.root=NULL;
}
template<class K,class V>
AVLTree<K,V> & AVLTree<K,V>::operator=(const AVLTree & t)
{   if(this==&t)
        return *this;
    clear();
    if(t.root!=NULL)
    {   root=copy(t.root);
        root->parent=NULL;
    }
    else
        root=NULL;
    return *this;
}
template<class K,class V>
AVLTree<K,V> & AVLTree<K,V>::operator=(AVLTree && t)
{   clear();
    root=t.root;
    t.root=NULL;
}
template<class K,class V>
bool AVLTree<K,V>::insert(K k,V v)
{   Pair f=find(k);
    if(f.second!=NULL)
        return 0;
    else if(f.first==NULL)
        root=new Node(k,v,1,1);
    else if(k>f.first->key)
    {   f.first->right=new Node(k,v,1,1,f.first);
        adjust(&(f.first->right));
    }
    else
    {   f.first->left=new Node(k,v,1,1,f.first);
        adjust(&(f.first->left));
    }
    return 1;
}
template<class K,class V>
bool AVLTree<K,V>::erase(K k)
{   Pair f=find(k);
    if(f.second==NULL)
        return 0;
    else if(f.first==NULL)
        delnode(&root);
    else if(f.first->left==f.second)
        delnode(&(f.first->left));
    else
        delnode(&(f.first->right));
    return 1;
}
template<class K,class V>
V AVLTree<K,V>::operator[](K k) const
{   Pair f=find(k);
    if(f.second!=NULL)
        return f.second->value;
    else 
        throw bad_key<K>(k);
}
template<class K,class V>
V & AVLTree<K,V>::operator[](K k)
{   Pair f=find(k);
    if(f.second!=NULL)
        return f.second->value;
    else 
        throw bad_key<K>(k);
}
template<class K,class V>
V AVLTree<K,V>::min()const
{   if(root==NULL)
        return;
    Node * temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp->value;
}
template<class K,class V>
V AVLTree<K,V>::max()const
{   if(root==NULL)
        return;
    Node * temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp->value;
}
template<class K,class V>
V AVLTree<K,V>::floor(K k)const
{   Node * p=NULL;
    Node * temp=root;
    while(temp!=NULL)
    {   if(k==temp->key)
            return temp->value;
        else if(k<temp->key)
            temp=temp->left;
        else
        {   p=temp;
            temp=temp->right;            
        }
    }
    if(p!=NULL)
        return p->value;
    else
        throw bad_key<K>(k);
}
template<class K,class V>
V AVLTree<K,V>::ceiling(K k)const
{   Node * p=NULL;
    Node * temp=root;
    while(temp!=NULL)
    {   if(k==temp->key)
            return temp->value;
        else if(k>temp->key)
            temp=temp->right;
        else
        {   p=temp;
            temp=temp->left;            
        }
    }
    if(p!=NULL)
        return p->value;
    else
        throw bad_key<K>(k);
}
template<class K,class V>
int AVLTree<K,V>::rank(K k)const
{   Node * p=NULL;
    Node * temp=root;
    while(temp!=NULL)
    {   if(k==temp->key)
            return temp->value;
        else if(k>temp->key)
            temp=temp->right;
        else
        {   p=temp;
            temp=temp->left;            
        }
    }
    if(p!=NULL)
        return p->value;
    else
        throw bad_key<K>(k);
}
template<class K,class V>
void AVLTree<K,V>::layer(void)const
{   queue<Node *> q;
    if(root!=NULL)
        q.push(root);
    while(q.size())
    {   cout<<q.front()->key<<" "<<q.front()->value<<" Height:"<<q.front()->height<<" Size:"<<q.front()->size<<endl;
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        q.pop();
    }
}
template<class K,class V>
void AVLTree<K,V>::clear(void)
{   if(root!=NULL)
        delall(root);
    root=NULL;
}
#endif