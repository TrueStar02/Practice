#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
void Show(string & s){cout<<s<<" ";}
int main(void)
{	string sa[4]={"a1","a2","c3","c4"};
	string sb[3]={"b1","b2","b3"};
	string sc[3]={"c1","c2","c3"};
	vector<string> words(4);
	copy(sa,sa+4,words.begin());
	copy(sb,sb+3,back_insert_iterator<vector<string>>(words));
	copy(sc,sc+3,insert_iterator<vector<string>>(words,words.begin()));
	for_each(words.begin(),words.end(),Show);
	cout<<endl<<words.size()<<endl;
	return 0;
}
