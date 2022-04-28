#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;
struct bomb{double stuff[1048576];};
int main()
{	bomb *pb;
	int n;
	{	cout<<"Guess!Do you have enough memory?\n";
		cout<<"One block is 8MB,how many do you want:";
		cin>>n;
		pb=new bomb[n];
	}
	catch(bad_alloc & ba)
	{	cout<<"BOOM!\n";
		cout<<ba.what()<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Luckily,you have allocated enough memory!\n";
	delete [] pb;
	cout<<"Bye~\n";
	return 0;
}
