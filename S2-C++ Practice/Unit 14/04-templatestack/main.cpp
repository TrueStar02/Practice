#include "Tstack.h"
#include<cctype>
#include<cstring>
struct Item
{	string task;
	int time;
};
char menu(void);
void Push(Stack<Item> & st);
int Pop(Stack<Item> & st);
void IsFull(Stack<Item> & st);
void IsEmpty(Stack<Item> & st);
void Count(Stack<Item> & st);
void Print(Item item);
void eatline(void);
int main(void)
{	Stack<Item> st;
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
void Push(Stack<Item> & st)
{	Item item;
	printf("Enter the task:");
	getline(cin,item.task);
	printf("Enter the time:");
	cin>>item.time;
	eatline();
	st.push(item);
	cout<<"Push successfully\n";
}
int Pop(Stack<Item> & st)
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
void IsFull(Stack<Item> & st)
{	if(st.isfull())
		cout<<"Stack<Item> is full\n";
	else
		cout<<"Stack<Item> isn't full\n";
}
void IsEmpty(Stack<Item> & st)
{	if(st.isempty())
		cout<<"Stack<Item> is empty\n";
	else
		cout<<"Stack<Item> isn't empty\n";
}
void Count(Stack<Item> & st)
{	cout<<"There are "<<st.count()<<" item(s) in the Stack<Item>\n";
}
void Print(Item item)
{	cout<<"Task:"<<item.task<<"   Time required:"<<item.time<<"min\n";
}
void eatline(void)
{	while((cin.get())!='\n')
		continue;
}
