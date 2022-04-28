#include<iostream>
#include<fstream>
using namespace std;
int main()
{	ifstream fin("file.txt");
	cout<<"Current file:\n";
	char ch;
	while(fin.get(ch))
		cout<<ch;
	fin.close();
	ofstream fout;
	fout.open("file.txt",ios_base::out|ios_base::app);
	string temp;
	cout<<"Enter a string,a blank line to terminate:";
	while(getline(cin,temp)&&temp.size()>0)
		fout<<temp<<endl;
	fout.close();
	cout<<"Bye~\n";
	return 0;                                                                          
}
