#include<set>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
void Show(const string & t){cout<<t<<" ";}
int main()
{	set<string> mat,pat;
	string name;
	cout<<"Enter the name of Mat's friend,\"quit\" for stop:";
	while(cin>>name&&name!="quit")
	{	cout<<"Enter the name of Mat's friend,\"quit\" for stop:";
		mat.insert(name);
	}
	cout<<"Enter the name of Pat's friend,\"quit\" for stop:";
	while(cin>>name&&name!="quit")
	{	cout<<"Enter the name of Pat's friend,\"quit\" for stop:";
		pat.insert(name);
	}
	set<string> tot;
	set_union(mat.begin(),mat.end(),pat.begin(),pat.end(),insert_iterator<set<string>>(tot,tot.begin()));
	cout<<"Mat's friend:";
	for_each(mat.begin(),mat.end(),Show);
	cout<<endl<<"Pat's friend:";
	for_each(pat.begin(),pat.end(),Show);
	cout<<endl<<"Union Set:";
	for_each(tot.begin(),tot.end(),Show);
	cout<<endl;
}
