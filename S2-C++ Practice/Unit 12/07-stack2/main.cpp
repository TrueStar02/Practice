#include "stack.h"
#include<cctype>
#include<cstring>
char menu(void);
void Push(Stack & st);
int Pop(Stack & st);
void IsFull(Stack & st);
void IsEmpty(Stack & st);
void Count(Stack & st);
void Print(Item item);
void eatline(void);
int main(void)
{	Stack st;
	char ch;
	int tot_time=0;
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':Push(st);
				break;
			case 'b':tot_time+=Pop(st);
				break;
			case 'c':IsFull(st);
				break;
			case 'd':IsEmpty(st);
				break;
			case 'e':Count(st);
				break;
			case 'f':st.traverse(Print);
				break;
		}
		cout<<"Time used:"<<tot_time<<" min\n";
	}
	Stack st2=st;
	st.~Stack();
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':Push(st2);
				break;
			case 'b':tot_time+=Pop(st2);
				break;
			case 'c':IsFull(st2);
				break;
			case 'd':IsEmpty(st2);
				break;
			case 'e':Count(st2);
				break;
			case 'f':st2.traverse(Print);
				break;
		}
		cout<<"Time used:"<<tot_time<<" min\n";
	}
	Stack st3;
	st3=st2;
	st2.~Stack();
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':Push(st3);
				break;
			case 'b':tot_time+=Pop(st3);
				break;
			case 'c':IsFull(st3);
				break;
			case 'd':IsEmpty(st3);
				break;
			case 'e':Count(st3);
				break;
			case 'f':st3.traverse(Print);
				break;
		}
		cout<<"Time used:"<<tot_time<<" min\n";
	}
	cout<<"Bye~\n";
	return 0;
}
char menu(void)
{	cout<<"A-Push B-Pop C-IsFull D-IsEmpty\n";
	cout<<"E-Count F-PrintAll Q-Quit\n";
	char ch=tolower(cin.get());
	while(strchr("abcdefq",ch)==NULL)
	{	eatline();
		cout<<"Enter A~F or Q!\n";
		ch=tolower(cin.get());
	}
	eatline();
	return ch;
}
void Push(Stack & st)
{	Item item;
	printf("Enter the task:");
	getline(cin,item.task);
	printf("Enter the time:");
	cin>>item.time;
	eatline();
	st.push(item);
	cout<<"Push successfully\n";
}
int Pop(Stack & st)
{	Item item;
	if(st.pop(item))
	{	cout<<"Pop successfully\n";
		cout<<"Task:"<<item.task<<",Time:"<<item.time<<"minutes";
		return item.time;
	}
	else
	{	cout<<"Pop failed\n";
		return 0;
	}	
}
void IsFull(Stack & st)
{	if(st.isfull())
		cout<<"Stack is full\n";
	else
		cout<<"Stack isn't full\n";
}
void IsEmpty(Stack & st)
{	if(st.isempty())
		cout<<"Stack is empty\n";
	else
		cout<<"Stack isn't empty\n";
}
void Count(Stack & st)
{	cout<<"There are "<<st.count()<<" item(s) in the stack\n";
}
void Print(Item item)
{	cout<<"Task:"<<item.task<<"   Time required:"<<item.time<<"min\n";
}
void eatline(void)
{	while((cin.get())!='\n')
		continue;
}
