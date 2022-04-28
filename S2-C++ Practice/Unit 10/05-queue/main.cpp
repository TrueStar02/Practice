#include "queue.h"
#include<cctype>
#include<cstring>
char menu(void);
void EnQueue(Queue & q);
int DeQueue(Queue & q);
void IsFull(Queue & q);
void IsEmpty(Queue & q);
void Count(Queue & q);
void Print(Item item);
void eatline(void);
int main(void)
{	Queue q;
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
void EnQueue(Queue & q)
{	Item item;
	cout<<"Enter the task:";
	getline(cin,item.task);
	cout<<"Enter the time:";
	cin>>item.time;
	eatline();
	q.enqueue(item);
	cout<<"Enqueue successfully\n";
}
int DeQueue(Queue & q)
{	Item item;
	if(q.dequeue(item))
	{	cout<<"Dequeue successfully\n";
		cout<<"Task:"<<item.task<<",Time:"<<item.time<<"minutes\n";
		return item.time;
	}
	else
	{	cout<<"Dequeue failed\n";
		return 0;
	}	
}
void IsFull(Queue & q)
{	if(q.isfull())
		cout<<"Queue is full\n";
	else
		cout<<"Queue isn't full\n";
}
void IsEmpty(Queue & q)
{	if(q.isempty())
		cout<<"Queue is empty\n";
	else
		cout<<"Queue isn't empty\n";
}
void Count(Queue & q)
{	cout<<"There are "<<q.count()<<" item(s) in the Queue\n";
}
void Print(Item item)
{	cout<<"Task:"<<item.task<<"   Time required:"<<item.time<<"min\n";
}
void eatline(void)
{	while((cin.get())!='\n')
		continue;
}
