#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<cstring>
using namespace std;
struct book
{	char name[21];
	double price;
	bool valid;
};
char menu(void);
void AddItem(fstream & f);
void SearchItem(fstream & f);
void PrintAll(fstream & f);
void DeleteItem(fstream & f);
int main()
{	cout.setf(ios_base::fixed,ios_base::floatfield);
	fstream finout;
	finout.open("file.txt",ios_base::in|ios_base::binary|ios_base::out);
	if(!finout.is_open())
	{	cerr<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	PrintAll(finout);
	char ch;
	while((ch=menu())&&ch!='q')
	{	finout.seekg(0);
		switch(ch)
		{	case 'a':AddItem(finout);
				break;
			case 'b':SearchItem(finout);
				break;
			case 'c':PrintAll(finout);
				break;
			case 'd':DeleteItem(finout);
				break;
		}
	}
	cout<<"Now let's see the final result:\n";
	finout.seekg(0);
	PrintAll(finout);
	finout.close();
	cout<<"Bye~\n";
	return 0;
}
void AddItem(fstream & f)
{	book temp,add;
	cout<<"Enter the book's name:";
	cin.get(add.name,81).get();
	cout<<"Enter the price:";
	(cin>>add.price).get();
	add.valid=1;
	while(f.read((char*)(&temp),sizeof(temp)))
	{	if(temp.valid==0)
		{	f.seekg(-sizeof(temp),ios_base::cur);
			f.write((char *)(&add),sizeof(temp));
			break;
		}
	}
	if(f.eof())
	{	f.clear();
		f.write((char *)(&add),sizeof(temp));
	}
}
void SearchItem(fstream & f)
{	book temp;
	char search[81];
	cout<<"Enter the book's name:";
	cin.get(search,81).get();
	while(f.read((char*)(&temp),sizeof(temp)))
	{	if(temp.valid&&!strcmp(search,temp.name))
		{	cout<<"Name:"<<setw(20)<<temp.name<<"   Price:$"<<setprecision(2)<<setw(6)<<temp.price<<endl;
			break;
		}
	}
	if(f.eof())
	{	f.clear();
		cout<<"Cannot find the item\n";
	}
}
void PrintAll(fstream & f)
{	book temp;
	cout<<"Current:\n";
	while(f.read((char*)(&temp),sizeof(temp)))
		if(temp.valid)
			cout<<"Name:"<<setw(20)<<temp.name<<"   Price:$"<<setprecision(2)<<setw(6)<<temp.price<<endl;
	f.clear();
}
void DeleteItem(fstream & f)
{	book temp;
	char search[81];
	cout<<"Enter the book's name:";
	cin.get(search,81).get();
	while(f.read((char*)(&temp),sizeof(temp)))
	{	if(temp.valid&&!strcmp(search,temp.name))
		{	temp.valid=0;
			f.seekg(-sizeof(temp),ios_base::cur);
			f.write((char *)(&temp),sizeof(temp));
			break;
		}
	}
	if(f.eof())
	{	f.clear();
		cout<<"Cannot find the item\n";
	}
}
char menu(void)
{	char v;
	cout<<"Choose the function:\n";
	cout<<"A-Add B-Search C-PrintAll\n";
	cout<<"D-Delete Q-Quit\n";
	cout<<"Your Choice:";
	while((v=tolower(cin.get()))&&strchr("abcdq",v)==NULL)
	{	cout<<"Enter A,B,C,D or Q!\n:";
		cin.ignore(255,'\n');
		cout<<"Your Choice:";
	}
	cin.ignore(255,'\n');
	return v;
}
