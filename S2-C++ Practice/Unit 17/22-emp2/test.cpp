#include<iostream>
#include<fstream>
#include<cstdlib>
#include "emp.h"
int main(void)
{	ifstream fin("data.txt");
	string fname; // abstr_emp's first name
    string lname; // abstr_emp's last name
    string job;
    int inchargeof;
    string reportsto;
	int type,count=-1,x;
	abstr_emp *ptr[10];
   	while((fin>>type).get()&&!fin.eof())
   	{	count++;
   		switch(type)
   		{	case 1:getline(fin,fname);
   				fin.get();
   				getline(fin,lname);
   				getline(fin,job);
   				ptr[count]=new employee(fname,lname,job);
   				break;
   			case 2:getline(fin,fname);
   				getline(fin,lname);
   				getline(fin,job);
   				fin>>inchargeof;
   				ptr[count]=new manager(fname,lname,job,inchargeof);
   				break;
   			case 3:getline(fin,fname);
   				getline(fin,lname);
   				getline(fin,job);
   				getline(fin,reportsto);
   				ptr[count]=new fink(fname,lname,job,reportsto);
   				break;
   			case 4:getline(fin,fname);
   				getline(fin,lname);
   				getline(fin,job);
   				getline(fin,reportsto);
   				fin>>inchargeof;
   				ptr[count]=new highfink(fname,lname,job,reportsto,inchargeof);
   				break;
   			default:
   				cerr<<"Error!\n";
   				exit(EXIT_FAILURE);
   		}
   	}
   	cout<<"Current:\n";
   	for(x=0;x<=count;x++)
   		ptr[x]->ShowAll();
   	fin.close();
   	ofstream fout;
   	fout.open("data.txt",ios_base::out|ios_base::app);
   	cout<<"Choose the type:";
   	while((cin>>type).get()&&type&&count<9)
   	{	count++;
   		switch(type)
   		{	case 1:ptr[count]=new employee;
   				ptr[count]->SetAll();
   				ptr[count]->Pure(fout);
   				break;
   			case 2:ptr[count]=new manager;
   				ptr[count]->SetAll();
   				ptr[count]->Pure(fout);
   				break;
   			case 3:ptr[count]=new fink;
   				ptr[count]->SetAll();
   				ptr[count]->Pure(fout);
   				break;
   			case 4:ptr[count]=new employee;
   				ptr[count]->SetAll();
   				ptr[count]->Pure(fout);
   				break;
   			default:
   				cerr<<"Error!\n";
   				exit(EXIT_FAILURE);
   		}
   	}
   	fout.close();
   	fin.open("data.txt");
   	while(fin>>type&&!fin.eof())
   	{	count++;
   		switch(type)
   		{	case 1:getline(fin,fname);
   				getline(fin,lname);
   				getline(fin,job);
   				ptr[count]=new employee(fname,lname,job);
   				break;
   			case 2:getline(fin,fname);
   				getline(fin,lname);
   				getline(fin,job);
   				fin>>inchargeof;
   				ptr[count]=new manager(fname,lname,job,inchargeof);
   				break;
   			case 3:getline(fin,fname);
   				getline(fin,lname);
   				getline(fin,job);
   				getline(fin,reportsto);
   				ptr[count]=new fink(fname,lname,job,reportsto);
   				break;
   			case 4:getline(fin,fname);
   				getline(fin,lname);
   				getline(fin,job);
   				getline(fin,reportsto);
   				fin>>inchargeof;
   				ptr[count]=new highfink(fname,lname,job,reportsto,inchargeof);
   				break;
   			default:
   				cerr<<"Error!\n";
   				exit(EXIT_FAILURE);
   		}
   	}
   	cout<<"bye~\n";
    return 0;
}

