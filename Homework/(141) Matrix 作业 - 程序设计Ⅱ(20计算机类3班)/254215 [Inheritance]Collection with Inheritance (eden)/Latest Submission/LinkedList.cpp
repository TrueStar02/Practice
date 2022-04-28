#include "LinkedList.hpp"
void MergeSort(LinkedList::node *& h,LinkedList::node *& t,int len);
LinkedList::LinkedList()
{   head=tail=NULL;
    _size=0;
}
LinkedList::~LinkedList(){clear();}
void LinkedList::add(E e)
{   if(head==NULL)
    {   head=new node(e);
        tail=head;
    }
    else
    {   tail->next=new node(e,NULL,tail);
        tail=tail->next;
    }
    _size++;
}
void LinkedList::clear(void)
{   node * ptr=head;
    while(ptr!=NULL)
    {   head=head->next;
        delete ptr;
        ptr=head;
    }
    _size=0;
    head=tail=NULL;
}
bool LinkedList::contain(E e)
{   node * ptr=head;
    while(ptr!=NULL)
    {   if(ptr->data==e)
            return 1;
        ptr=ptr->next;
    }
    return 0;
}
bool LinkedList::isEmpty(void){return !_size;}
void LinkedList::remove(E e)
{   node * ptr=head,* temp;
    while(ptr!=NULL)
    {   if(ptr->data==e)
        {   if(_size==1)
            {   delete ptr;
                ptr=NULL;
                head=tail=NULL;
                _size=0;
            }
            else
            {   temp=ptr;
                ptr=ptr->next;               
                if(temp!=head)
                    temp->prev->next=temp->next;
                else
                    head=temp->next;
                if(temp!=tail)
                    temp->next->prev=temp->prev;
                else
                    tail=temp->prev;
                delete temp;
                _size--;
            }
        }
        else
            ptr=ptr->next;       
    }
}
E& LinkedList::operator[](int index)
{   int x;
    node * ptr;
    for(x=0,ptr=head;x<index&&ptr!=NULL;x++,ptr=ptr->next)
        continue;
    return ptr->data;
}
E& LinkedList::get(int index)
{   int x;
    node * ptr;
    for(x=0,ptr=head;x<index&&ptr!=NULL;x++,ptr=ptr->next)
        continue;
    return ptr->data;
}
int LinkedList::indexOf(E element)
{   node * ptr=head;
    int count=0;
    while(ptr!=NULL)
    {   if(ptr->data==element)
            return count;
        ptr=ptr->next;
        count++;
    }
    return -1;
}
void LinkedList::sort(void)
{   MergeSort(head,tail,_size);
}
int LinkedList::size(void){return _size;}
void MergeSort(LinkedList::node *& h,LinkedList::node *& t,int len)
{   if(len>=2)
    {   LinkedList::node * head1,* tail1,* head2,* tail2;
        head1=tail1=h;
        tail2=t;
        int x;
        for(x=0;x<len/2-1;x++)
            tail1=tail1->next;
        head2=tail1->next;
        head2->prev=NULL;
        tail1->next=NULL;
        MergeSort(head1,tail1,len/2);
        MergeSort(head2,tail2,len-len/2);
        h=t=NULL;
        if(head1->data<head2->data)
        {   h=head1;
            head1=head1->next;
            h->next=NULL;
            if(head1!=NULL)
                head1->prev=NULL;
            t=h;
        }
        else
        {   h=head2;
            head2=head2->next;
            h->next=NULL;
            if(head2!=NULL)
                head2->prev=NULL;
            t=h;
        }
        for(x=1;x<len;x++)
        {   if(head1==NULL)
            {   t->next=head2;
                t->next->prev=t;
                head2=head2->next;
                t=t->next;
                t->next=NULL;
                if(head2!=NULL)
                    head2->prev=NULL;
            }
            else if(head2==NULL)
            {   t->next=head1;
                t->next->prev=t;
                head1=head1->next;
                t=t->next;
                t->next=NULL;
                if(head1!=NULL)
                    head1->prev=NULL;
            }
            else if(head1->data>head2->data)
            {   t->next=head2;
                t->next->prev=t;
                head2=head2->next;
                t=t->next;
                t->next=NULL;
                if(head2!=NULL)
                    head2->prev=NULL;
            }
            else
            {   t->next=head1;
                t->next->prev=t;
                head1=head1->next;
                t=t->next;
                t->next=NULL;
                if(head1!=NULL)
                    head1->prev=NULL;
            }
        }
    }

}