#include "Stack.hpp"
 Stack::Stack()
 {  p.data=NULL;
 }
   Stack::Stack(const Stack& s)
   {    node * temp=s.p.data,* ntemp;
        if(s.p.data==NULL)
            p.data=NULL;
        else
        {   p.data=new node(s.p.data->num);
            ntemp=p.data;
            while(temp->next!=NULL)
            {   ntemp->next=new node(temp->next->num);
                temp=temp->next;
                ntemp=ntemp->next;
            }
        }

   }           // 深拷贝
   Stack::~Stack()
   {    node * temp=p.data;
    if(temp!=NULL)
    {    while(temp->next!=NULL)
        {   p.data=p.data->next;
            delete temp;
            temp=p.data;
        } 
        delete temp;
    }
          p.data=NULL;                      // 注意内存回收
    }
  Stack  Stack::operator=(const Stack&s)
   {    if(this==&s)
            return *this;
       node * temp=p.data;
       if(p.data!=NULL)
       {while(temp->next!=NULL)
        {   p.data=p.data->next;
            delete temp;
            temp=p.data;
        }    
        delete temp;
       }
        p.data=NULL;     
       temp=s.p.data;
       node * ntemp;
        if(s.p.data==NULL)
            p.data=NULL;
        else
        {   p.data=new node(s.p.data->num);
            ntemp=p.data;
            while(temp->next!=NULL)
            {   ntemp->next=new node(temp->next->num);
                temp=temp->next;
                ntemp=ntemp->next;
            }
        }
    return *this;
   }    
  // 深拷贝
  void  Stack::push(int x)
  {     node * newnode=new node(x);
        if(p.data==NULL)
            p.data=newnode;
        else
        {   node * temp=p.data;
             while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }

  }            // 入栈
  void  Stack::pop()
  {    if(p.data==NULL)p.data=NULL;
      else if(p.data->next==NULL)
        {  delete p.data;
            p.data=NULL;
        }
       else
       {   node * temp=p.data;
            while(temp->next->next!=NULL)
                temp=temp->next;
            delete temp->next;
            temp->next=NULL;
       } 

  }                     // 出栈
  int  Stack::top() const
  {  node * temp=p.data;
     while(temp->next!=NULL)
        temp=temp->next;
    return temp->num;
  }               // 查看栈顶元素
  bool  Stack::empty() const
  {
      return p.data==NULL;
  }            // 判断栈是否为空
  void  Stack::clear()
  {     node * temp=p.data;
        if(temp!=NULL)
       { while(temp->next!=NULL)
        {   p.data=p.data->next;
            delete temp;
            temp=p.data;
        }
        delete temp;
       }
        p.data=NULL;
  }               // 清空栈