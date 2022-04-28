#include<iostream>
#include<vector>
using namespace std;
int main(void)
{	vector<int> v1;
	int x;
	for(x=0;x<10;x++)
		v1.push_back(x);
	cout<<"The size of v1:"<<v1.size()<<endl;
	vector<int> v2;
	for(x=0;x<100;x++)
		v2.push_back(100+x);
	vector<int>::iterator i;
	i=v1.begin();
	v2.erase(v2.begin()+30,v2.begin()+40);
	v2.insert(v2.begin()+30,i,i+10);
	cout<<"The size of v2:"<<v2.size()<<endl;
	for(x=0;x<100;x++)
	{	cout<<v2[x]<<" ";
		if(x%10==9)
			cout<<endl;
	}
	return 0;
}
