#include<iostream>
#include<fstream>
using namespace std;
struct Detail
{	string name;
	int money;
};
int main(void)
{	ifstream fin;
	ofstream fout;
	fin.open("filestruct.in");
	fout.open("filestruct.out");
	int n,x;
	fin>>n;
	Detail people[n];
	for(x=0;x<n;x++)
	{	fin.get();
		getline(fin,people[x].name);
		fin>>people[x].money;
	}
	for(x=0;x<n;x++)
		fout<<"#"<<x+1<<":"<<people[x].name<<" donated $"<<people[x].money<<endl;
	fin.close();
	fout.close();
	return 0;
}
