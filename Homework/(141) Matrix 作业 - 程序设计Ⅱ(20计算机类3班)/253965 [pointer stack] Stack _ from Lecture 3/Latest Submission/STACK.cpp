#include "STACK.h"
#include<iostream>
using namespace std;
STACK::STACK(){top=NULL;}  // 构造函数，设置栈顶为空指针
STACK::~STACK() // 析构函数，释放堆栈结点占用的存储空间
{   NODE * temp=top; 
    if(top!=NULL)
    while(top->link!=NULL)
    {   top=top->link;
        delete temp;
        temp=top;
    }
}
void STACK::push(ELEMENT obj)
{   NODE * n=new NODE;
    n->element=obj;
    n->link=top;
    top=n;
}
void STACK::pop()
{   if(top==NULL)return;
    NODE * temp=top;
    top=top->link;
    delete temp;
} // 将当前栈顶的元素弹出栈中。要求：栈不为空。
ELEMENT STACK::get_top() const{if(top!=NULL)return top->element;} 
bool STACK::is_empty() const {return top==NULL;}  
void STACK::display() const 
{   NODE * temp=top;
    while(temp!=NULL)
    {    cout<<temp->element<<" ";
        temp=temp->link;
    }
    cout<<endl;

}  // 自顶向下显示堆栈中的元素