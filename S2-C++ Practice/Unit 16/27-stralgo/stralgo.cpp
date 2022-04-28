#include<iostream>
#include<algorithm>
using namespace std;
int main()
{	string letters;
	cout<<"Enter a word:";
	cin>>letters;
	sort(letters.begin(),letters.end());
	cout<<letters<<endl;
	while(next_permutation(letters.begin(),letters.end()))
		cout<<letters<<endl;
	return 0;
}
