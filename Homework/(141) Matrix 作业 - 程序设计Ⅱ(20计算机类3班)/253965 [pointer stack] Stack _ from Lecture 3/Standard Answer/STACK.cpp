#include "STACK.h"
#include <iostream>
#include<cstdlib>
using namespace std;


STACK::STACK()
{
     top = NULL;		// 将栈顶置为空
}

STACK::~STACK()
{
    NODE* ptr;   // 指向堆栈结点的临时指针

   while (top != NULL)   // 从上到下释放堆栈的结点，注意循环体中语句的次序
   {			
        ptr = top;	             // 先记住将被摘下来的栈顶结点
        top = top->link;	// 摘下栈顶结点
        delete ptr;		// 释放刚才被摘下来的结点
    }
}
void STACK::push(ELEMENT obj)  // 将obj压入堆栈的栈顶
{
    NODE* temp;
    temp = new NODE;	   // 创建一个新结点
    if (temp != NULL)         // 内存分配成功时
   {	
        temp->link = top; 
        temp->element = obj;
        top = temp;
    } 
    else   // 内存分配失败时作异常处理
   {	
          cout << "Error: No enough memory."<< endl;
          exit(1);		// 终止程序
    }
}
void STACK::pop() // 将堆栈当前的栈顶元素弹出
{
       NODE* temp;
       if (top != NULL) // 堆栈不为空时才处理
      {		
             temp = top;	// 将栈顶元素弹出堆栈
	top = top->link;
	delete temp;	// 释放被弹出结点占用的存储空间
       }
       else    // 空栈时作异常处理
      {	
               cout << "Error: Pop from empty stack.\n";
               exit(1); 		// 终止程序
       }
}
ELEMENT STACK::get_top() const  // 返回当前栈顶的元素值
{
     if (top == NULL)    // 空栈时作异常处理
    {					
	cout << "Error: Get top from empty stack.\n";
	exit(1); 	         // 终止程序
    }
    return top->element;    // 返回栈顶的当前值
}

bool STACK::is_empty() const // 判断当前堆栈是否为空，空则返回1，非空则返回0
{
     return (top == NULL);
}
void STACK::display() const // 自顶向下显示堆栈中的元素
{
     NODE* loop;

    loop = top;
    while (loop != NULL)  // 以空指针作为链的结束标记
    {				 
         cout << loop->element << " ";    // 将当前结点的元素输出
         loop = loop->link;		     // 指向下一个结点
     }
  cout<<endl;
}

