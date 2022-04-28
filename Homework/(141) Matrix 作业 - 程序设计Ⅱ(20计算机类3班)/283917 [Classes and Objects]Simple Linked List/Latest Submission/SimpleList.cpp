#include "SimpleList.hpp"
#include<sstream>
using namespace std;
list::list()
{   head=NULL;
    _size=0;
}
list::list(const list& l)
{       head=NULL;
        _size=l._size;
         node * temp=l.head;
        if(temp!=NULL)
       { head=new node(l.head->data);
       		node * ntemp=head;
        while(temp->next!=NULL)
        {   ntemp->next=new node(temp->next->data);
            ntemp=ntemp->next;
            temp=temp->next;
        }
       }
}
list& list::operator=(const list& l)
{   if(&l==this)
        return * this;
    clear();
    
    node * temp=l.head;
    _size=l._size;
    if(temp!=NULL)
   { head=new node(l.head->data);
    node * ntemp=head;
    
        while(temp->next!=NULL)
        {   ntemp->next=new node(temp->next->data);
            ntemp=ntemp->next;
            temp=temp->next;
        }
   }
    return *this;
}
list::~list()
{   node * temp=head;
    while(head!=NULL)
    {   head=head->next;
        delete temp;
        temp=head;
    }
}
bool list::empty(void) const{return !_size;}
int list::size(void) const{return _size;}
std::string list::toString(void) const
{   ostringstream strout;
    node * temp=head;
    while(temp!=NULL)
    {   strout<<temp->data<<"->";
        temp=temp->next;
    }
    strout<<"NULL";
    return strout.str();
}
void list::insert(int position, const int& data)
{   if(head==NULL)
    {    if(position==0)
        head=new node(data);
        else return;
    }
    else if(position==0)
    {   node * n=new node(data);
        n->next=head;
        head=n;
    }
    else
    {   node *n=new node(data);
        node * temp=head;
        for(int x=1;x<position;x++)
        {    temp=temp->next;
            if(temp==NULL)
                return;
        }
        if(temp==NULL)
                return;
        n->next=temp->next;
        temp->next=n;
    }
    _size++;
}
void list::erase(int position)
{    node * temp=head;
    if(head!=NULL)
    {if(position==0)
    {   node * temp=head;
    	head=head->next;
        delete temp;
    }
    else
    {   for(int x=1;x<position;x++)
         {   temp=temp->next;
             if(temp->next==NULL)
                return;
         }
         if(temp->next==NULL)
                return;
        node * temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;

    }
    _size--;
    }
}
list& list::sort(void)
{   node * nhead=NULL;
    node * temp=head;
    node * ntemp=nhead;
    while(temp!=NULL)
    {   if(nhead==NULL)
            nhead=new node(temp->data);
        else if(temp->data<nhead->data)
        {   node * nnode=new node(temp->data);
            nnode->next=nhead;
            nhead=nnode;
        }
        else
        {   for(ntemp=nhead;ntemp->next!=NULL&&ntemp->next->data<temp->data;ntemp=ntemp->next)continue;
                 node * nnode=new node(temp->data);
                 nnode->next=ntemp->next;
                ntemp->next=nnode;

        }
        temp=temp->next;
    }
    int s=_size;
    clear();
    _size=s;
    head=nhead;
    return *this;
}