#include "Stack.hpp"

Stack::Stack()
  {
      data=new node();
  }                        // 构造一个空栈
Stack::Stack(const Stack& t)            // 深拷贝
    {
        node* p=new node();
        p->num=t.data->num;
        p->next=t.data->next;
        data=p;
        while(p->next!=NULL)
        {
            node* temp=new node();
            temp->num=p->next->num;
            temp->next=p->next->next;
            p->next=temp;
            p=temp;
        }
    }
  Stack::~Stack()                 // 注意内存回收
    {
        node* temp=data->next;
        node* t1=data;
        while(temp!=NULL)
        {
            delete t1;
            t1=temp;
            temp=temp->next;
        }
        delete t1;
        data=NULL;
    }
  Stack Stack::operator=(const Stack& t)
  {
       Stack st(t);
        node* p=new node();
        p->num=t.data->num;
        p->next=t.data->next;
        data=p;
        while(p->next!=NULL)
        {
            node* temp=new node();
            temp->num=p->next->num;
            temp->next=p->next->next;
            p->next=temp;
            p=temp;
        }
        return st;
    }
  // 深拷贝
  void Stack::push(int n)
  {
      node* temp=new node();
    temp->num=n;
    temp->next=data;
    data=temp;
  }                 // 入栈
  void Stack::pop()
  {
      node* temp=data;
      data=data->next;
      delete temp;
      temp=NULL;
  }                     // 出栈
  int Stack::top() const
  {
      return data->num;
  }                // 查看栈顶元素
  bool Stack::empty() const
  {
      if(data->next==NULL&&data->num==0) return 1;
      else return 0;
  }             // 判断栈是否为空
  void Stack::clear()
  {
        node* temp=data->next;
        node* t1=data;
        while(temp!=NULL)
        {
            delete t1;
            t1=temp;
            temp=temp->next;
        }
        data=t1;
  }