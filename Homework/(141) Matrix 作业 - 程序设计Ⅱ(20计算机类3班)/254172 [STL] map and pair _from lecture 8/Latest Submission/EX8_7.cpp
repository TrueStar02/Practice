#include <iostream>
#include <map>
using namespace std;
int main() {
	map <char, int>m;
	int x;
	
    for(x=65;x<=65+25;x++)
        m.insert(pair<char,int>(x,x));
	
	char ch;
	cout <<"enter key:";
	cin >>ch;
	map<char, int>::iterator p;
	
	p=m.equal_range(ch).first;
	
	if (p!=m.end())
		cout <<"Its ASCII value is " <<p->second;
	else
		cout <<"Key not in map." ;
	return 0;
}