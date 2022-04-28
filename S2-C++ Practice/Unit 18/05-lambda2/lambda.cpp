#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
void Rand(int &x){x=rand();}
using namespace std;
int main()
{	srand((unsigned int)time(0));
	vector<int> num(1000000);
	for_each(num.begin(),num.end(),Rand);
	cout<<"Size:1000000\n";
	int count3=0,count13=0;
	for_each(num.begin(),num.end(),[&](int x){count3+=!(x%3);count13+=!(x%13);});
	cout<<"Divisible by 3:"<<count3<<endl;
	cout<<"Divisible by 13:"<<count13<<endl;
	return 0;
}
