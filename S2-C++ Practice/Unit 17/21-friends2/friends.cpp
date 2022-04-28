#include<set>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<fstream>
using namespace std;
void Show(const string & t){cout<<t<<endl;}
int main()
{	set<string> mat,pat;
	string name;
	ifstream finm("mat.txt");
	ifstream finp("pat.txt");
	ofstream fout("all.txt");
	while(getline(finm,name)&&!finm.eof())
		mat.insert(name);
	while(getline(finp,name)&&!finp.eof())
		pat.insert(name);
	set<string> tot;
	set_union(mat.begin(),mat.end(),pat.begin(),pat.end(),insert_iterator<set<string>>(tot,tot.begin()));
	cout<<"Mat's friend:\n";
	for_each(mat.begin(),mat.end(),Show);
	cout<<"Pat's friend:\n";
	for_each(pat.begin(),pat.end(),Show);
	cout<<"Union Set:\n";
	for_each(tot.begin(),tot.end(),Show);
	set<string>::iterator ptr;
	for(ptr=tot.begin();ptr!=tot.end();ptr++)
		fout<<*ptr<<endl;
	return 0;
}
