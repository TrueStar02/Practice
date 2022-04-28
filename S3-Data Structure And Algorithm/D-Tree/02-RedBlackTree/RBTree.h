#ifndef RBTREE_H_
#define RBTREE_H_
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
class RBTree
{   private:
        class Node
        {   public:
                K key;
                V value;
                int size;
                bool isred;
                Node * parent;
                Node * left;
                Node * right;
                Node(K k,V v,int s=1,bool i=1,Node * p=NULL,Node * l=NULL,Node * r=NULL):key(k),value(v),size(s),isred(i),parent(p),left(l),right(r){}
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
        void delnode(Node ** p);
        void addadjust(Node ** p);
        void deladjust(Node ** p,bool right);
        void BothRed(Node ** p);
        void PLIL(Node ** p);
        void PLIR(Node ** p);
        void PRIR(Node ** p);
        void PRIL(Node ** p);
        void BLNL(Node ** p);
        void BLNR(Node ** p);
        void BRNR(Node ** p);
        void BRNL(Node ** p);
        void RedBroL(Node ** p);
        void RedBroR(Node ** p);
        void leftrotate(Node & p);
        void rightrotate(Node & p);
        void printall(Node * n)const;
        void delall(Node * p);
    public:
        RBTree(){root=NULL;}
        RBTree(const RBTree & t);
        RBTree(RBTree && t);
        ~RBTree(){clear();}
        RBTree & operator=(const RBTree & t);
        RBTree & operator=(RBTree && t);
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
int RBTree<K,V>::getsize(Node * p) const
{   if(p==NULL)
        return 0;
    else
        return p->size;
}
template<class K,class V>
typename RBTree<K,V>::Pair RBTree<K,V>::find(K key)const
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
typename RBTree<K,V>::Node * RBTree<K,V>::copy(Node * src)
{   Node * newnode=new Node(src->key,src->value,src->size,src->isred);
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
void RBTree<K,V>::delnode(Node ** p)
{   bool c;
    Node * temp=(*p);
    if((*p)->left==NULL&&(*p)->right==NULL)
    {   c=(*p)->isred;
        Node * parent=(*p)->parent;
        if(!c&&parent!=NULL)
        {   if(parent->left==temp)
                deladjust(&parent,0);
            else
                deladjust(&parent,1); 
        }
        (*p)=NULL;
        delete temp;        
    }
    else if((*p)->left==NULL)
    {   (*p)->right->isred=0;
        (*p)->right->parent=(*p)->parent;
        (*p)=(*p)->right;
        delete temp;
    }
    else if((*p)->right==NULL)
    {   (*p)->left->isred=0;
        (*p)->left->parent=(*p)->parent;
        (*p)=(*p)->left;
        delete temp;
    }
    else
    {   Pair temp(*p,(*p)->left);
        while(temp.second->right!=NULL)
        {   temp.second->size--;
            temp.first=temp.second;
            temp.second=temp.second->right;
        }
        (*p)->key=temp.second->key;
        (*p)->value=temp.second->value;
        if(temp.second->left==NULL)
        {   c=temp.second->isred;
            if((*p)==temp.first)
                temp.first->left=NULL;
            else    
                temp.first->right=NULL;
            if(!c)
            {   if((*p)!=temp.first)
                    deladjust(&(temp.first),1);
                else
                    deladjust(&(temp.first),0);
            }
            delete temp.second;      
        }
        else
        {   temp.second->left->isred=0;
            temp.second->left->parent=temp.first;
            if((*p)!=temp.first)
                temp.first->right=temp.second->left;
            else
                temp.first->left=temp.second->left;
            delete temp.second;
        }
    }
}
template<class K,class V>
void RBTree<K,V>::addadjust(Node ** p)
{   if((*p)->parent==NULL)
        (*p)->isred=0;
    else if((*p)->parent->isred)
    {   if((*p)->parent->parent->left==(*p)->parent)
        {   if((*p)->parent->parent->right!=NULL&&(*p)->parent->parent->right->isred)
                BothRed(&((*p)->parent->parent));
            else if((*p)->parent->left==(*p))
                PLIL(&((*p)->parent->parent));
            else
                PLIR(&((*p)->parent->parent));
        }
        else if((*p)->parent->parent->right==(*p)->parent)
        {   if((*p)->parent->parent->left!=NULL&&(*p)->parent->parent->left->isred)
                BothRed(&((*p)->parent->parent));
            else if((*p)->parent->left==(*p))
                PRIL(&((*p)->parent->parent));
            else
                PRIR(&((*p)->parent->parent));
        }
    }
}
template<class K,class V>
void RBTree<K,V>::deladjust(Node ** p,bool right)
{   if((*p)->right!=NULL&&!right)
    {   if(!(*p)->right->isred)
        {   if((*p)->right->right!=NULL&&(*p)->right->right->isred)
                BRNR(p);
            else if((*p)->right->left!=NULL&&(*p)->right->left->isred)
                BRNL(p);
            else if((*p)->isred)
            {   (*p)->isred=0;
                (*p)->right->isred=1;
            }
            else
            {   (*p)->right->isred=1;
                if((*p)->parent!=NULL)
                {   if((*p)->parent->left==(*p))
                        deladjust(&((*p)->parent),0);
                    else
                        deladjust(&((*p)->parent),1);
                }
            }
        }
        else
           RedBroR(p);
    }
    else
    {   if(!(*p)->left->isred)
        {   if((*p)->left->left!=NULL&&(*p)->left->left->isred)
                BLNL(p);
            else if((*p)->left->right!=NULL&&(*p)->left->right->isred)
                BLNR(p);
            else if((*p)->isred)
            {   (*p)->isred=0;
                (*p)->left->isred=1;
            }
            else
            {   (*p)->left->isred=1;
                if((*p)->parent!=NULL)
                {   if((*p)->parent->left==(*p))
                        deladjust(&((*p)->parent),0);
                    else
                        deladjust(&((*p)->parent),1);
                }
            }
        }
        else
            RedBroL(p);
    }
}
template<class K,class V>
void RBTree<K,V>::BothRed(Node ** p)
{   (*p)->isred=1;
    (*p)->left->isred=0;
    (*p)->right->isred=0;
    addadjust(p);
}
template<class K,class V>
void RBTree<K,V>::PLIL(Node ** p)
{   (*p)->isred=1;
    (*p)->left->isred=0;
    rightrotate(**p);
}
template<class K,class V>
void RBTree<K,V>::PLIR(Node ** p)
{   leftrotate(*((*p)->left));
    PLIL(&((*p)->parent));
}
template<class K,class V>
void RBTree<K,V>::PRIR(Node ** p)
{   (*p)->isred=1;
    (*p)->right->isred=0;
    leftrotate(**p);
}
template<class K,class V>
void RBTree<K,V>::PRIL(Node ** p)
{   rightrotate((*(*p)->right));
    PRIR(&((*p)->parent));
}
template<class K,class V>
void RBTree<K,V>::BLNL(Node ** p)
{   (*p)->left->isred=(*p)->isred;
    (*p)->isred=0;
    (*p)->left->left->isred=0;
    rightrotate(**p);
}
template<class K,class V>
void RBTree<K,V>::BLNR(Node ** p)
{   (*p)->left->right->isred=0;
    (*p)->left->isred=1;
    leftrotate(*((*p)->left));
    BLNL(p);
}
template<class K,class V>
void RBTree<K,V>::BRNR(Node ** p)
{   (*p)->right->isred=(*p)->isred;
    (*p)->isred=0;
    (*p)->right->right->isred=0;
    leftrotate(**p);
}
template<class K,class V>
void RBTree<K,V>::BRNL(Node ** p)
{   (*p)->right->left->isred=0;
    (*p)->right->isred=1;
    rightrotate(*((*p)->right));
    BRNR(p);
}
template<class K,class V>
void RBTree<K,V>::RedBroL(Node ** p)
{   (*p)->isred=1;
    (*p)->left->isred=0;
    rightrotate(**p);
    deladjust(p,1);
}
template<class K,class V>
void RBTree<K,V>::RedBroR(Node ** p)
{   (*p)->isred=1;
    (*p)->right->isred=0;
    leftrotate(**p);
    deladjust(p,0);
}
template<class K,class V>
void RBTree<K,V>::leftrotate(Node & p)
{   Node * temp=p.right;
    p.right=temp->left;
    if(temp->left!=NULL)
        temp->left->parent=(&p);
    temp->parent=p.parent;
    if(p.parent==NULL)    
        root=temp;
    else if(p.parent->left==(&p))
        p.parent->left=temp;
    else
        p.parent->right=temp;
    temp->left=(&p);     
    p.parent=temp;
    p.size=1+getsize(p.left)+getsize(p.right);
    p.parent->size=1+getsize(p.parent->left)+getsize(p.parent->right);
}
template<class K,class V>
void RBTree<K,V>::rightrotate(Node & p)
{   Node * temp=p.left;
    p.left=temp->right;
    if(temp->right!=NULL)
        temp->right->parent=(&p);
    temp->parent=p.parent;
    if(p.parent==NULL)
        root=temp;
    else if(p.parent->left==(&p))
        p.parent->left=temp;
    else
        p.parent->right=temp;
    temp->right=(&p);
    p.parent=temp;
    p.size=1+getsize(p.left)+getsize(p.right);
    p.parent->size=1+getsize(p.parent->left)+getsize(p.parent->right);
}
template<class K,class V>
void RBTree<K,V>::printall(Node * n)const
{   if(n!=NULL)
    {   printall(n->left);
        cout<<n->key<<" "<<n->value<<" "<<"Size:"<<n->size<<endl;
        printall(n->right);
    }
}
template<class K,class V>
void RBTree<K,V>::delall(Node * p)
{   Node * temp=p->right;
    if(p->left!=NULL)
        delall(p->left);
    delete p;
    if(temp!=NULL)
        delall(temp);
}
template<class K,class V>
RBTree<K,V>::RBTree(const RBTree & t)
{   if(t.root!=NULL)
    {   root=copy(t.root);
        root->parent=NULL;
    }
    else
        root=NULL;    
}
template<class K,class V>
RBTree<K,V>::RBTree(RBTree && t)
{   root=t.root;
    t.root=NULL;
}
template<class K,class V>
RBTree<K,V> & RBTree<K,V>::operator=(const RBTree & t)
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
RBTree<K,V> & RBTree<K,V>::operator=(RBTree && t)
{   clear();
    root=t.root;
    t.root=NULL;
}
template<class K,class V>
bool RBTree<K,V>::insert(K k,V v)
{   Pair f=find(k);
    if(f.second!=NULL)
        return 0;
    else if(root==NULL)
       root=new Node(k,v,1,0,NULL);
    else if(k>f.first->key)
    {   f.first->right=new Node(k,v,1,1,f.first);
        addadjust(&(f.first->right));
    }
    else
    {   f.first->left=new Node(k,v,1,1,f.first);
        addadjust(&(f.first->left));
    }
    Node * temp=f.first;
    while(temp!=NULL)
    {   temp->size=1+getsize(temp->left)+getsize(temp->right);
        temp=temp->parent;
    }
    return 1;
}
template<class K,class V>
bool RBTree<K,V>::erase(K k)
{   Pair f=find(k);
    Node * temp;
    if(f.second==NULL)
        return 0;
    else if(f.first==NULL)
    {   delnode(&root);
        temp=root;
    }
    else 
    {   if(f.first->right==f.second)
            delnode(&(f.first->right));
        else
            delnode(&(f.first->left));
        if(f.second==NULL)
            temp=f.first;
        else
            temp=f.second;
    }
    while(temp!=NULL)
    {   temp->size=1+getsize(temp->left)+getsize(temp->right);
        temp=temp->parent;
    }
    return 1;
}
template<class K,class V>
V RBTree<K,V>::operator[](K k) const
{   Pair f=find(k);
    if(f.second!=NULL)
        return f.second->value;
    else 
        throw bad_key<K>(k);
}
template<class K,class V>
V & RBTree<K,V>::operator[](K k)
{   Pair f=find(k);
    if(f.second!=NULL)
        return f.second->value;
    else 
        throw bad_key<K>(k);
}
template<class K,class V>
V RBTree<K,V>::min()const
{   if(root==NULL)
        return;
    Node * temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp->value;
}
template<class K,class V>
V RBTree<K,V>::max()const
{   if(root==NULL)
        return;
    Node * temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp->value;
}
template<class K,class V>
V RBTree<K,V>::floor(K k)const
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
V RBTree<K,V>::ceiling(K k)const
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
int RBTree<K,V>::rank(K k)const
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
void RBTree<K,V>::layer(void)const
{   queue<Node *> q;
    if(root!=NULL)
        q.push(root);
    while(q.size())
    {   cout<<q.front()->key<<" "<<q.front()->value<<" Color:"<<q.front()->isred<<" Size:"<<q.front()->size<<endl;
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        q.pop();
    }
}
template<class K,class V>
void RBTree<K,V>::clear(void)
{   if(root!=NULL)
        delall(root);
    root=NULL;
}
#endif