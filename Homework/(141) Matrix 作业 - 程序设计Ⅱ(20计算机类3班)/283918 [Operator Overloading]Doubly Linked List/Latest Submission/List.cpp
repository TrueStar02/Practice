#include "List.hpp"
#include<sstream>
#include<iostream>
#include<set>
using namespace std;
list::list()
{
    head=tail=NULL;
    _size=0;
}
  // construct a list from an exist array
list::list(const data_type arr[], int length)
{   if(length==0)
    {   head=tail=NULL;
        _size=0;
    }
    else
    {   _size=length;
        int x;
        head=new node(arr[0]);
        node * temp=head;
        for(x=1;x<length;x++)
        {   temp->next=new node(arr[x],NULL,temp);
            temp=temp->next;
        }
        tail=temp;
    }

}
list::list(const list& l)
{   if(l._size==0)
    {   _size=0;
        head=tail=NULL;
    }
    else
    {   _size=l._size;
        head=new node(l.head->data);
        node * temp=l.head;
        node * ntemp=head;
        while(temp->next!=NULL)
        {   ntemp->next=new node(temp->next->data,NULL,ntemp);
            ntemp=ntemp->next;
            temp=temp->next;
        }
        tail=ntemp;
    }
}
list& list::operator=(const list& l)
{   if(&l==this)
        return *this;
    clear();
    if(l._size==0)
    {   _size=0;
        head=tail=NULL;
    }
    else
    {   _size=l._size;
        head=new node(l.head->data);
        node * temp=l.head;
        node * ntemp=head;
        while(temp->next!=NULL)
        {   ntemp->next=new node(temp->next->data,NULL,ntemp);
            ntemp=ntemp->next;
            temp=temp->next;
        }
        tail=ntemp;
    }
    return *this;
}
  list::~list(){clear();}
  // Capacity
bool list::empty(void) const{return !_size;}
list::size_type list::size(void) const{return _size;}

  // Element access
list::data_type& list::front(void) const{if(head==NULL) return *(int *)NULL;return head->data;}
list::data_type& list::back(void) const{if(head==NULL) return *(int *)NULL;return tail->data;}

  // output
std::string list::toString(void) const
{   ostringstream strout;
    strout<<"NULL";
    if(head!=NULL)
    {   bool flag=0;
        node * temp=head;
        while(temp!=NULL)
        {   if(!flag)
                strout<<"<-"<<temp->data;
            else
                strout<<"<->"<<temp->data;
            temp=temp->next;
            flag=1;
        }
        strout<<"->NULL";
    }
    return strout.str();
}
void list::assign(const list& l)
{    clear();
    if(l._size==0)
    {   _size=0;
        head=tail=NULL;
    }
    else
    {   _size=l._size;
        head=new node(l.head->data);
        node * temp=l.head;
        node * ntemp=head;
        while(temp->next!=NULL)
        {   ntemp->next=new node(temp->next->data,NULL,ntemp);
            ntemp=ntemp->next;
            temp=temp->next;
        }
        tail=ntemp;
    }
}
void list::assign(const data_type datas[], int length)
{   clear();
    if(length==0)
    {   head=tail=NULL;
        _size=0;
    }
    else
    {   _size=length;
        int x;
        head=new node(datas[0]);
        node * temp=head;
        for(x=1;x<length;x++)
        {   temp->next=new node(datas[x],NULL,temp);
            temp=temp->next;
        }
        tail=temp;
    }
}
void list::push_front(const data_type& i)
{   _size++;
    if(head==NULL)
    {   head=new node(i);
        tail=head;
    }
    else
    {   head->prev=new node(i,head);
        head=head->prev;
    }
}
void list::push_back(const data_type& i)
{   _size++;
    if(head==NULL)
    {   head=new node(i);
        tail=head;
    }
    else
    {   tail->next=new node(i,NULL,tail);
        tail=tail->next;
    }
}
void list::pop_front(void)
{   _size--;
    if(head->next==NULL)
    {   delete head;
        head=tail=NULL;
    }
    else
    {   node * temp=head;
        head=head->next;
        delete temp;
        head->prev=NULL;
    }
}
void list::pop_back(void)
{    _size--;
    if(head->next==NULL)
    {   delete head;
        head=tail=NULL;
    }
    else
    {   node * temp=tail;
        tail=tail->prev;
        delete temp;
        tail->next=NULL;
    }
}
void list::insert(int position, const data_type& data)
{   if(head==NULL)
    {   if(position==0)
        {    head=new node(data);
            tail=head;
        }
        else return;
    }
    else if(position==0)
    {   node * nnode=new node(data);
        nnode->next=head;
        head->prev=nnode;
        head=nnode;
    }
    else
    {   int x;
        node * temp;
        for(x=1,temp=head;x<position&&temp!=NULL;x++,temp=temp->next)
            continue;
        if(temp==NULL)return;
        node * nnode=new node(data,temp->next,temp);
        if(temp->next!=NULL)
            temp->next->prev=nnode;
        else
            tail=nnode;
        temp->next=nnode;
    }
    _size++;
}
void list::erase(int position)
{   if(head==NULL)return;
    if(position==0)
    {  if(head->next==NULL)
        {   delete head;
            head=tail=NULL;
        }
        else
        {   node * temp=head;
            head=head->next;
            delete temp;
            head->prev=NULL;
        }
    }
    else
    {   int x;
        node * temp;
        for(x=1,temp=head;x<=position&&temp!=NULL;x++,temp=temp->next)
            continue;
        if(temp==NULL)return;
        if(temp->next==NULL)
            tail=temp->prev;
        else
            temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        delete temp;
    }
    _size--;
}
void list::clear(void)
{   _size=0;
    node * temp=head;
    while(head!=NULL)
    {   head=head->next;
        delete temp;
        temp=head;
    }
}

  // Operations
  // split this list into to lists at the given position
void list::split(int position, list* des1, list* des2)
{   des1->clear();
	des2->clear();
	if(position==0)
    {   
        *des2=*this;
        return;
    }
    *des1=*this;
    node * temp;
    int x;
    for(x=1,temp=des1->head;x<=position;x++,temp=temp->next)
            continue;
    if(temp!=NULL)
    {   des2->tail=des1->tail;
        des1->tail=temp->prev;
    	des2->head=temp;
        temp->prev->next=NULL;
        des2->head->prev=NULL;
        des1->_size=position;
        des2->_size=_size-position;
    }
}
  // merge two list to this list from src1 and src2
list& list::merge(const list& sr1, const list& sr2)
{   list src1(sr1),src2(sr2);
	clear();
	*this=src1;
	if(src2.head==NULL)return *this;
	if(head==NULL)
	{	head=new node(src2.head->data);
		tail=head;
	}
	else
	{	tail->next=new node(src2.head->data,NULL,tail);
		tail->next->prev=tail;
		tail=tail->next;
	}
	node * temp=src2.head->next;
	while(temp!=NULL)
	{	tail->next=new node(temp->data,NULL,tail);
		temp=temp->next;
		tail=tail->next;
	}
	_size+=src2._size;	
    return *this;
}
  // remove the elements who satisfy the condition
list& list::remove_if(bool (*condition)(listPointer))
{   node * temp=head;

    while(temp!=NULL)
    {   
    	if(condition(temp))
        {   
        	
            if(temp->prev==NULL)
            {   temp=temp->next;
                pop_front();
            }
            else if(temp->next==NULL)
            {   pop_back();
                break;
            }
            else
            {   _size--;
            	node * temp2=temp;
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                temp=temp->next;
                delete temp2;
            }
        }
        else
        	temp=temp->next;
       
    }
    return *this;
}

  // remove duplicate elements
list& list::unique(void)
{   node * temp=head;
	if(head!=NULL)
    {	_size/=4;
    	set<int> num;
    	int x,count=0;
    	for(x=1;x<=_size;x++)
    	{	if(num.find(temp->data)==num.end())
    		{	num.insert(temp->data);
    			temp=temp->next;
    		}
    		else
    		{	temp->prev->next=temp->next;
    			temp->next->prev=temp->prev;
    			node * temp2=temp;
    			temp=temp->next;
    			delete temp2;
    			count++;
    		}
    	}
    	_size-=count;
    	tail=temp->prev;
    	temp->prev->next=NULL;
    	node * temp2=temp;
    	while(temp!=NULL)
    	{	temp=temp->next;
    		delete temp2;
    		temp2=temp;
    	}
    }
    return *this;
}
  // reverse the list
list & list::reverse(void)
{   return *this;

}
list::data_type & list::operator[](int index)
{   if(index==0)return head->data;
    int x;
    node * temp;
    for(x=1,temp=head;x<=index&&temp!=NULL;x++,temp=temp->next)
        continue;
    return temp->data;
}
list& list::operator+=(const list& l)
{	if(l.head==NULL)return *this;
	if(head==NULL)
	{	head=new node(l.head->data);
		tail=head;
	}
	else
	{	tail->next=new node(l.head->data,NULL,tail);
		tail->next->prev=tail;
		tail=tail->next;
	}
	node * temp=l.head->next;
	while(temp!=NULL)
	{	tail->next=new node(temp->data,NULL,tail);
		temp=temp->next;
		tail=tail->next;
	}	
	_size+=l._size;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const list& li)
{
    os<<li.toString();
    return os;
}