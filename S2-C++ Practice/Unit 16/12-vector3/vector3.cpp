#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct review
{	string name;
	int rating;
};
void Show(const review & r){cout<<"Name:"<<r.name<<" Rating:"<<r.rating<<endl;}
bool Comp(const review & r1,const review & r2);
int main(void)
{	vector<review> books;
	int x;
	review temp;
	for(x=0;x<5;x++)
	{	cout<<"Enter the name:";
		getline(cin,temp.name);
		cout<<"Enter the rating:";
		cin>>temp.rating;
		cin.get();
		books.push_back(temp); 
	}
	cout<<"Original:\n";
	for_each(books.begin(),books.end(),Show);
	random_shuffle(books.begin(),books.end());
	cout<<"Random:\n";
	for_each(books.begin(),books.end(),Show);
	sort(books.begin(),books.end(),Comp);
	cout<<"Sorted:\n";
	for_each(books.begin(),books.end(),Show);
	return 0;
}
bool Comp(const review & r1,const review & r2)
{	if(r1.rating<r2.rating)
		return 0;
	else if((r1.rating==r2.rating)&&(r1.name>r2.name))
		return 0;
	else
		return 1;
}
