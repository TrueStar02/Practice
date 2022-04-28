#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(void)
{	ifstream fin;
	ofstream fout;
	fin.open("filesum.in");
	fout.open("filesum.out");
	if((!(fin.is_open()))||(!(fout.is_open())))
	{	cout<<"Error in poening files!\n";
		exit(EXIT_FAILURE);
	}
	int sum=0,num;
	while(fin.good())
	{	fin>>num;
		sum+=num;
	}
	fout<<sum;
	fin.close();
	fout.close();
	return 0;
}
