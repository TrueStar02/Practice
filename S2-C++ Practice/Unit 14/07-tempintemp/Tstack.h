#ifndef TSTACK_H_
#define TSTACK_H_
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
template<class Type>
class Stack
{	private:
		int max;
		int top;
		Type * items;
	public:
		explicit Stack(int m=10);
		Stack(const Stack & st);
		~Stack(){delete [] items;}
		bool push(const Type & item);
		bool pop(Type & item);
		bool isempty() const{return !top;}
		bool isfull() const{return !(max-top);}
		int count()const{return top;}
		void traverse(void (*pf)(Type item));
		Stack<Type> & operator=(const Stack & st);
};
template<class Type>
Stack<Type>::Stack(int m)
{	max=m;
	top=0;
	items=new Type[m];
}
template<class Type>
Stack<Type>::Stack(const Stack & st)
{	max=st.max;
	top=st.top;
	items=new Type[max];
	memcpy(items,st.items,top*sizeof(Type));
}
template<class Type>
bool Stack<Type>::push(const Type & item)
{	if(top<max)
	{	memcpy(items+top*sizeof(Type),&item,sizeof(Type));
		top++;
		return 1;
	}
	else
		return 0;
}
template<class Type>
bool Stack<Type>::pop(Type & item)
{	if(top)
	{	memcpy(&item,items+(top-1)*sizeof(Type),sizeof(Type));
		top--;
		return 1;
	}
	else
		return 0;
}
template<class Type>
void Stack<Type>::traverse(void (*pf)(Type item))
{	int x;
	for(x=0;x<top;x++)
		pf(items[x]);
}
template<class Type>
Stack<Type> & Stack<Type>::operator=(const Stack & st)
{	if(&st==this)
		return *this;
	else
	{	delete [] items;
		max=st.max;
		top=st.top;
		items=new Type[max];
		memcpy(items,st.items,top*sizeof(Type));
		return *this;
	}
}
#endif
