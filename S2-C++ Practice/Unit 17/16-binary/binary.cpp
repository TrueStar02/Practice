#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
struct book
{	char name[21];
	double price;
};
using namespace std;
int main()
{	cout.setf(ios_base::fixed,ios_base::floatfield);
	ifstream fin;
	fin.open("file.txt",ios_base::in|ios_base::binary);
	if(!fin.is_open())
	{	cerr<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	book temp;
	cout<<"Current:\n";
	while(fin.read((char*)(&temp),sizeof(temp)))
		cout<<"Name:"<<setw(20)<<temp.name<<"   Price:$"<<setprecision(2)<<setw(6)<<temp.price<<endl;
	fin.close();
	ofstream fout;
	fout.open("file.txt",ios_base::out|ios_base::app|ios_base::binary);
	if(!fout.is_open())
	{	cerr<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	cout<<"Enter the name:";
	cin.get(temp.name,21);
	cin.get();
	while(temp.name[0]!='\0')
	{	cout<<"Enter the price:";
		cin>>temp.price;
		cin.get();
		fout.write((char*)(&temp),sizeof(temp));
		cout<<"Enter the name:";
		cin.get(temp.name,21);
		cin.get();
	}
	fout.close();
	fin.open("file.txt",ios_base::in|ios_base::binary);
	if(!fin.is_open())
	{	cerr<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	cout<<"After append:\n";
	while(fin.read((char *)(&temp),sizeof(temp)))
		cout<<"Name:"<<setw(20)<<temp.name<<"   Price:$"<<setprecision(2)<<setw(6)<<temp.price<<endl;
	fin.close();
	cout<<"Bye~\n";
	return 0;
}
