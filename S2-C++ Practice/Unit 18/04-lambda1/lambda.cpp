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
	cout<<"Divisible by 3:"<<count_if(num.begin(),num.end(),[](int x){return !(x%3);})<<endl;
	cout<<"Divisible by 13:"<<count_if(num.begin(),num.end(),[](int x){return !(x%13);})<<endl;
	return 0;
}
