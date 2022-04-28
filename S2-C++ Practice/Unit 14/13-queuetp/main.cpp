#include "queuetp.h"
#include<cctype>
#include<cstring>
struct Item
{	string task;
	int time;
};
char menu(void);
void EnQueue(Queue<Item> & q);
int DeQueue(Queue<Item> & q);
void IsFull(Queue<Item> & q);
void IsEmpty(Queue<Item> & q);
void Count(Queue<Item> & q);
void Print(Item item);
void eatline(void);
int main(void)
{	Queue<Item> q;
	char ch;
	int tot_time=0;
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':EnQueue(q);
				break;
			case 'b':tot_time+=DeQueue(q);
				break;
			case 'c':IsFull(q);
				break;
			case 'd':IsEmpty(q);
				break;
			case 'e':Count(q);
				break;
			case 'f':q.traverse(Print);
				break;
		}
		cout<<"Time used:"<<tot_time<<" min\n";
	}
	cout<<"Bye~\n";
	return 0;
}
char menu(void)
{	cout<<"A-EnQueue B-DeQueue C-IsFull D-IsEmpty\n";
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
void EnQueue(Queue<Item> & q)
{	Item item;
	cout<<"Enter the task:";
	getline(cin,item.task);
	cout<<"Enter the time:";
	cin>>item.time;
	eatline();
	q.enqueue(item);
	cout<<"EnQueue successfully\n";
}
int DeQueue(Queue<Item> & q)
{	Item item;
	if(q.dequeue(item))
	{	cout<<"DeQueue<Item> successfully\n";
		cout<<"Task:"<<item.task<<",Time:"<<item.time<<"minutes\n";
		return item.time;
	}
	else
	{	cout<<"DeQueue<Item> failed\n";
		return 0;
	}	
}
void IsFull(Queue<Item> & q)
{	if(q.isfull())
		cout<<"Queue is full\n";
	else
		cout<<"Queue isn't full\n";
}
void IsEmpty(Queue<Item> & q)
{	if(q.isempty())
		cout<<"Queue is empty\n";
	else
		cout<<"Queue isn't empty\n";
}
void Count(Queue<Item> & q)
{	cout<<"There are "<<q.count()<<" item(s) in the Queue\n";
}
void Print(Item item)
{	cout<<"Task:"<<item.task<<"   Time required:"<<item.time<<"min\n";
}
void eatline(void)
{	while((cin.get())!='\n')
		continue;
}
