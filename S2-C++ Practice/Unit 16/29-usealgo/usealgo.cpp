#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cctype>
using namespace std;
string & ToLower(string & t);
int main()
{	vector<string> ori;
	set<string> words;
	map<string,int> wordmap;
	string temp;
	while((cin>>temp)&&(temp!="quit"))
		ori.push_back(temp);
	transform(ori.begin(),ori.end(),insert_iterator<set<string>>(words,words.begin()),ToLower);
	set<string>::iterator iter;
	for(iter=words.begin();iter!=words.end();iter++)
		wordmap.insert(pair<string,int>(*iter,count(ori.begin(),ori.end(),*iter)));
	for(iter=words.begin();iter!=words.end();iter++)
		cout<<*iter<<":"<<wordmap[*iter]<<endl;
	return 0; 
}
string & ToLower(string & t)
{	int x;
	for(x=0;x<t.length();x++)
		t[x]=tolower(t[x]);
	return t;
}
