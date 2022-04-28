#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
struct review
{	string name;
	int rating;
	double price;
};
char menu(void);
void eatline(void);
void Show(const shared_ptr<review> & r){cout<<"Name:"<<(*r).name<<" Rating:"<<(*r).rating<<" Price:"<<(*r).price<<endl;}
bool operator<(const shared_ptr<review> & r1,const shared_ptr<review> & r2);
bool Comp_pri(const shared_ptr<review> & r1,const shared_ptr<review> & r2);
bool Comp_rat(const shared_ptr<review> & r1,const shared_ptr<review> & r2);
int main(void)
{	vector<shared_ptr<review>> books,copy;
	int x;
	review temp;
	for(x=0;x<8;x++)
	{	cout<<"Enter the name:";
		getline(cin,temp.name);
		cout<<"Enter the rating:";
		cin>>temp.rating;
		cout<<"Enter the price:";
		cin>>temp.price;
		cin.get();
		books.push_back(shared_ptr<review>(new review(temp)));
		copy.push_back(shared_ptr<review>(new review(temp))); 
	}
	char ch;
	while((ch=menu())&&ch!='q')
		switch(ch)
		{	case 'a':for_each(books.begin(),books.end(),Show);
				break;
			case 'b':sort(copy.begin(),copy.end());
				for_each(copy.begin(),copy.end(),Show);
				break;
			case 'c':sort(copy.begin(),copy.end(),Comp_rat);
				for_each(copy.begin(),copy.end(),Show);
				break;
			case 'd':sort(copy.begin(),copy.end(),Comp_rat);
				for_each(copy.rbegin(),copy.rend(),Show);
				break;
			case 'e':sort(copy.begin(),copy.end(),Comp_pri);
				for_each(copy.begin(),copy.end(),Show);
				break;
			case 'f':sort(copy.begin(),copy.end(),Comp_pri);
				for_each(copy.rbegin(),copy.rend(),Show);
				break;
		}
	cout<<"Bye!\n";
	return 0;
}
bool operator<(const shared_ptr<review> & r1,const shared_ptr<review> & r2)
{	if(r1->name>r2->name)
		return 0;
	if(r1->name==r2->name&&r1->rating>r2->rating)
		return 0;
	if(r1->name==r2->name&&r1->rating==r2->rating&&r1->price>r2->price)
		return 0;
	return 1;
}
bool Comp_pri(const shared_ptr<review> & r1,const shared_ptr<review> & r2)
{	if(r1->price>r2->price)
		return 0;
	if(r1->price==r2->price&&r1->rating>r2->rating)
		return 0;
	if(r1->price==r2->price&&r1->rating==r2->rating&&r1->name>r2->name)
		return 0;
	return 1;
}
bool Comp_rat(const shared_ptr<review> & r1,const shared_ptr<review> & r2)
{	if(r1->rating>r2->rating)
		return 0;
	if(r1->rating==r2->rating&&r1->price>r2->price)
		return 0;
	if(r1->rating==r2->rating&&r1->price==r2->price&&r1->name>r2->name)
		return 0;
	return 1;
}
char menu(void)
{	cout<<"Choose the display mode(q for quit):\n";
	cout<<"A-Original     B-Alphabatical C-Rating Upper\n";
	cout<<"D-Rating Lower E-Price Upper  F-Price Lower\n";
	cout<<"Your choice:";
	char v;
	if((v=tolower(cin.get()))&&strchr("abcdefq",v)==NULL)
	{	eatline();
		cout<<"Enter A~F or Q!";
	}
	eatline();
	return v;
}
void eatline(void)
{	while(cin.get()!='\n')
		continue;
}
