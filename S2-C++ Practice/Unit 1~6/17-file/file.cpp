#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void swap(string *str1,string *str2);
int main(void)
{	ifstream fin;
	ofstream fout;
	fin.open("file.in");
	fout.open("file.out");
	if((!fin.is_open())||(!fout.is_open()))
	{	cout<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	int n,x,y;
	fin>>n;
	string str[n];
	for(x=0;x<n;x++)
		fin>>str[x];
	for(x=0;x<n-1;x++)
	for(y=x+1;y<n;y++)
	{	if(str[x].length()<str[y].length())
			swap(str+x,str+y);
		else if((str[x].length()==str[y].length())&&str[x]<str[y])
			swap(str+x,str+y);
	}	
	for(x=0;x<n;x++)
		fout<<"#"<<x+1<<" "<<str[x]<<endl;
	fin.close();
	fout.close();
	return 0;
}
void swap(string *str1,string *str2)
{	string temp;
	temp=*str1;
	*str1=*str2;
	*str2=temp;
}
