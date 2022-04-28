#include<iostream>
#include<cctype>
#include<stack>
#include<cstring>
#include<algorithm>
#include<iterator>
using namespace std;
class Item
{	public:
		string task;
		int time;
		Item(const string & s,int t):task(s),time(t){}
		Item():task(""),time(0){}
};
typedef stack<Item> Stack;
char menu(void);
void Push(Stack & st);
int Pop(Stack & st);
void IsFull(Stack & st);
void IsEmpty(Stack & st);
void Count(Stack & st);
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
		}
		cout<<"Time used:"<<tot_time<<" min\n";
	}
	cout<<"Bye~\n";
	return 0;
}
char menu(void)
{	cout<<"A-Push B-Pop C-IsFull\n";
	cout<<"D-IsEmpty E-Count Q-Quit\n";
	char ch=tolower(cin.get());
	while(strchr("abcdeq",ch)==NULL)
	{	eatline();
		cout<<"Enter A~E or Q!\n";
		ch=tolower(cin.get());
	}
	eatline();
	return ch;
}
void Push(Stack & st)
{	string task;
	int time;
	printf("Enter the task:");
	getline(cin,task);
	printf("Enter the time:");
	cin>>time;
	eatline();
	st.push(Item(task,time));
	cout<<"Push successfully\n";
}
int Pop(Stack & st)
{	Item item;
	if(!st.empty())
	{	cout<<"Pop successfully\n";
		item=st.top();
		cout<<"Task:"<<item.task<<",Time:"<<item.time<<"minutes";
		st.pop();
		return item.time;
	}
	else
	{	cout<<"Pop failed\n";
		return 0;
	}	
}
void IsFull(Stack & st)
{	if(st.size()>100000)
		cout<<"Stack is full\n";
	else
		cout<<"Stack isn't full\n";
}
void IsEmpty(Stack & st)
{	if(st.empty())
		cout<<"Stack is empty\n";
	else
		cout<<"Stack isn't empty\n";
}
void Count(Stack & st)
{	cout<<"There are "<<st.size()<<" item(s) in the stack\n";
}
void eatline(void)
{	while((cin.get())!='\n')
		continue;
}
