#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<iomanip>
using namespace std;//My English is very poor but I don't have Chinese input method in Linux
struct Good         //So don't laugh at me if you find some spell or grammar mistakes!
{	char name[81];
	double amount;
	bool isvalid;
};
void Print(int ct,Good & g);//Print a detail
void Star(void);
void Init(char * p);
char menu(void);
void Add(fstream & fp);
void Delete(fstream & fp);
void Search(fstream & fp);
void PrintAll(fstream & fp);
bool Guard(char * p);
void Change(fstream & fp,char * p);
void Readme(void);//Some hints
bool confirm(void);//You can cancel your option here
double GetNum(void);//Make sure that the input is valid
int main(void)
{	fstream fp;
	fp.open("data.txt",ios_base::binary|ios_base::out|ios_base::in);
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.precision(3);
	char password[16],ch;
	fp.read(password,16);
	if(fp.eof())//Initialization
	{	fp.clear();
		Star();
		cout<<"Welcome to use the cargo-management system!\n";
		cout<<"Initialization\n";
		Init(password);
		fp.write(password,16);//write the password at the beginning of the file
 		cout<<"OK!\n";
	}
	if(Guard(password))//If the password is correct
		while((ch=menu())!='q')
		{	switch(ch)
			{	case 'a':Add(fp);
					break;
				case 'b':Delete(fp);
					break;
				case 'c':Search(fp);
					break;
				case 'd':PrintAll(fp);
					break;
				case 'e':if(!Guard(password))
					ch='q';
					break;
				case 'f':Change(fp,password);
					if(!Guard(password))
						ch='q';
					break;
				case 'g':Readme();
					break;
			}
			if(ch=='q')
				break;
		}
	fp.close();
	cout<<"Thanks for using the system,bye~\n";
	return 0;
}
void Add(fstream & fp)
{	Star();
	cout<<"Function:Add Item\n:";
	fp.seekg(16);//Byte 0~15 is password
	Good temp,add;
	add.amount=0;
	add.isvalid=1;
	cout<<"Enter the good's name:";
	cin.get(add.name,81).get();
	while(fp.read((char*)&temp,sizeof(Good)))//To see whether the good is already in the system
		if(!strcmp(temp.name,add.name)&&temp.isvalid)
		{	fp.seekg(-sizeof(Good),ios_base::cur);//move the fp object ahead of the detail we need
			break;
		}
	if(fp.eof())//if the good isn't  in the system
	{	fp.clear();
		fp.seekg(16);
		cout<<"There are no this kind of good here!\n";
		cout<<"How many do you wants to add(0 to cancel)";
		add.amount=GetNum();
		cin.ignore(999,'\n');
		if(add.amount>0)
		{	cout<<"Press Y/y to confirm and other to cancel:";//Are you sure?
			if(confirm())//If you're sure
			{	while(fp.read((char*)&temp,sizeof(Good)))
					if(temp.isvalid==0)//To find an available place
					{	fp.seekg(-sizeof(Good),ios_base::cur);//move the fp object ahead of the useless detail
						fp.write((char *)&add,sizeof(Good));//cover the useless detail
						break;
					}
				if(fp.eof())//No useless detail
				{	fp.clear();
					fp.write((char *)&add,sizeof(Good));//write the detail at the end of the file
				}
				cout<<"Succeed!\n";
			}
			else//If you have regretted
				cout<<"Cancelled\n";
		}
		else if(add.amount==0)//Maybe you have eaten too much...
			cout<<"Cancelled\n";
		else//I think you are crazy
			cout<<"Error:Amount can't be negative!\n";
	}
	else//if the good is in the system
	{	cout<<"There are "<<temp.amount<<" this kind of good!\n";
		cout<<"How many do you wants to add(0 to cancel)";
		add.amount=GetNum();
		cin.ignore(999,'\n');
		add.amount+=temp.amount;
		if(add.amount>0)
		{	cout<<"Press Y/y to confirm and other to cancel:";//Are you sure?
			if(confirm())//If you're sure
			{	fp.write((char *)&add,sizeof(Good));//Using new data to cover
				cout<<"Succeed!\n";
			}
			else//If you have regretted
				cout<<"Cancelled\n";
		}
		else if(add.amount==0)//Maybe you have eaten too much...
			cout<<"Cancelled\n";
		else//I think you are crazy
			cout<<"Error:Amount can't be negative!\n";
	}
}
void Delete(fstream & fp)
{	Star();
	cout<<"Function:Delete Item\n";
	fp.seekg(16);
	Good temp,del;
	del.isvalid=1;
	cout<<"Enter the good's name:";
	cin.get(del.name,81).get();
	while(fp.read((char*)&temp,sizeof(Good)))//To see whether the good is already in the system
		if(!strcmp(temp.name,del.name)&&temp.isvalid)
		{	fp.seekg(-sizeof(Good),ios_base::cur);//move the fp object ahead of the detail we need
			break;
		}
	if(fp.eof())//if the good isn't in the system
	{	cout<<"Cannot find this item!\n";
		fp.clear();
	}
	else//if the good is in the system
	{	cout<<"There are "<<temp.amount<<" this kind of good!\n";
		cout<<"How many do you wants to delete(0 to cancel)";
		del.amount=GetNum();
		cin.ignore(999,'\n');
		if(del.amount==0)//Maybe you have eaten too much...
			cout<<"Cancelled\n";
		else if(del.amount<0)//I think you are crazy
			cout<<"Error:Amount can't be negative!\n";
		else
		{	del.amount=-del.amount+temp.amount;
			if(del.amount>-0.0005)
			{	if(del.amount<0.0005&&del.amount>-0.0005)
					del.isvalid=0;//If delete all the goods
				fp.write((char *)&del,sizeof(Good));
				cout<<"Succeed!\n";
			}
			else//The good isn't good
				cout<<"Error:You don't have enough goods!\n";
		}
	}
}
void Search(fstream & fp)
{	Star();
	cout<<"Function:Search Item\n";
	string tmp,srch;
	int x,len;
	cout<<"Enter the item you need(fuzzy search is supported):";
	getline(cin,tmp);
	for(x=0;x<tmp.length();x++)//Ignore the space and make it case insensitive
		if(tmp[x]!=' ')
			srch+=tolower(tmp[x]);
	fp.seekg(16);
	Good temp;
	int ct=0;
	cout<<setw(3)<<"No."<<setw(20)<<"Name"<<setw(12)<<"Amount"<<endl;
	while(fp.read((char *)&temp,sizeof(Good)))//read a detail each time
		if(temp.isvalid)//If it is valid
		{	tmp="";
			len=strlen(temp.name);
			for(x=0;x<len;x++)//
				if(temp.name[x]!=' ')
					tmp+=tolower(temp.name[x]);//Ignore the space and make it case insensitive
			if(tmp.find(srch)!=string::npos)//If it is qualified
			{	ct++;
				Print(ct,temp);
			}
	}
	fp.clear();
	cout<<"Total:"<<ct<<endl;
	cout<<"Press any key to go back to the menu\n";
	cin.get();
}
void Readme(void)
{	Star();
	cout<<"Cargo Management System\n";
	cout<<"This program can only compile in Linux\n";
	cout<<"If you compile it in Windows\n";
	cout<<"The password system may cause some problems.\n";
	cout<<"If you can't remember the detail's name\n";
	cout<<"Use PrintAll to see the detail \n";
	cout<<"or use Search to fuzzy search\n\n";
	cout<<"Produced by Edward Bian(20337171)\n";
	cout<<"Press enter to go back to the menu\n";
	cin.ignore(999,'\n');
}
void PrintAll(fstream & fp)
{	Star();
	cout<<"Function:Print All\n";
	fp.seekg(16);
	Good temp;
	int ct=0;
	cout<<setw(3)<<"No."<<setw(20)<<"Name"<<setw(12)<<"Amount"<<endl;
	while(fp.read((char *)&temp,sizeof(Good)))
		if(temp.isvalid)
		{	ct++;
			Print(ct,temp);
		}
	fp.clear();
	cout<<"Press enter to go back to the menu\n";
	cin.ignore(999,'\n');
}
bool Guard(char * p)
{	Star();
	bool flag;//1 means the pasword is right and 0 means exit
	char ch;
	int x;
	cout<<"System is locked!\n";
	cout<<"Enter the password or enter \"quit\" to exit\n";
	string temp="";
	while(1)
	{	temp="";
		cout<<"Enter the password:";
		setvbuf(stdin,NULL,_IONBF,0);//No buffer
		setvbuf(stdout,NULL,_IONBF,0);//No buffer
		system("stty -echo");//Linux only.hide the input
		while((ch=cin.get())&&ch!=10)//red chars and output *
 		{	temp+=ch;
 			cout.put('*');
 		}
 		for(x=temp.length();x<16;x++)//Make sure the string length is 16
 			temp+=' ';
 		cout<<endl;
 		system("stty echo");//Linux only.Cancel the hide of the input
 		setvbuf(stdin,NULL,_IOFBF,4096);//Full buffer
 		setvbuf(stdout,NULL,_IOFBF,4096);//Full buffer
 		if(temp==p)//If the password is right
 		{	flag=1;
 			break;
 		}
 		else if(temp=="quit            ")//If you want to quit
 		{	flag=0;
 			break;
 		}
 		else//If you're wrong
 			cout<<"You're wrong!\n";
 	}
 	return flag;
}
char menu(void)
{	Star();
	char v;
	cout<<"Welcome to use the cargo-management system!\n";
	cout<<"Choose the function you need:\n";
	cout<<"A-Add goods   B-Delete goods   C-Search goods\n";
	cout<<"D-Print all items   E-Lock the system\n";
	cout<<"F-Change Password   G-Readme   Q-Quit\n";
	while((v=tolower(cin.get()))&&strchr("abcdefgq",v)==NULL)//c getchar() adjhfilaseofhgsioghfeoif
	{	cin.ignore(999,'\n');
		cout<<"Enter A~E or Q:";
	}	
	cin.ignore(999,'\n');
	Star();
	return v;
}
void Change(fstream & fp,char * p)
{	Star();
	cout<<"Function:Change Password\n";
	int x;
	char ch;
	string temp="";
	setvbuf(stdin,NULL,_IONBF,0);//No buffer
	setvbuf(stdout,NULL,_IONBF,0);//No buffer
	system("stty -echo");//Linux only.hide the input
	while(temp!=p)
	{	temp="";
		cout<<"Enter the old password:";//It should make sure that you know the old password
		while((ch=cin.get())&&ch!=10)//read the input and output *
 		{	temp+=ch;
 			cout.put('*');
 		}
 		cout<<endl;
 		for(x=temp.length();x<16;x++)//Make sure the string length is 16
 			temp+=' ';
 	}
 	system("stty echo");//Linux only.Cancel the hide of the input
 	setvbuf(stdin,NULL,_IOFBF,4096);//Full buffer
 	setvbuf(stdout,NULL,_IOFBF,4096);//Full buffer
 	Init(p);//Set new password
 	fp.seekg(0);
 	fp.write(p,16);//write the password at the beginning of the file
}
void Init(char * p)
{	string temp1,temp2;
	bool flag=0;//if the password is valid,it is 1
	char ch;
	while(!flag)
	{	temp1=temp2="";
		cout<<"Set password:    ";
		setvbuf(stdin,NULL,_IONBF,0);//No buffer
		setvbuf(stdout,NULL,_IONBF,0);//No buffer
		system("stty -echo");//Linux only.hide the input
		while((ch=cin.get())&&ch!=10)//Get the password
 		{	temp1+=ch;//read the input and output *
 			cout.put('*');
 		}
 		cout<<endl;
 		system("stty echo");//Linux only.Cancel the hide of the input
 		if(temp1.length()>16||temp1.length()<6||temp1.find(' ')!=string::npos)//If the password is invalid
 		{	cout<<"Length between 6~16 and no space!\n";
 			continue;
 		}
 		cout<<"Confirm password:";
 		system("stty -echo");//Linux only.hide the input
 		while((ch=cin.get())&&ch!=10)//Get the password
 		{	temp2+=ch;//read the input and output *
 			cout.put('*');
 		}
 		cout<<endl;
 		system("stty echo");//Linux only.Cancel the hide of the input
 		if(temp1!=temp2)//If the passwords are not same
 		{	cout<<"The password you have entered is not the same!\n";
 			continue;
 		}
 		flag=1;//Succeed
 	}
 	setvbuf(stdin,NULL,_IOFBF,4096);//Full buffer
 	setvbuf(stdout,NULL,_IOFBF,4096);//Full buffer
 	int x;
 	if(temp1.length()!=16)//Make sure the string length is 16
 		for(x=temp1.length();x<16;x++)
 			temp1+=' ';
 	strcpy(p,temp1.data());//Update the space
}
bool confirm(void)
{	char ch=tolower(cin.get());
	cin.ignore(999,'\n');
	if(ch=='y')
		return 1;
	return 0;
}
void Star(void)
{	int x;
	for(x=0;x<40;x++)
		cout<<'*';
	cout<<endl;
}
void Print(int ct,Good & g)
{	cout<<setw(3)<<ct<<setw(20)<<g.name<<setw(12)<<g.amount<<endl;
}
double GetNum(void)
{	double num;
	cin>>num;
	while(cin.fail())//If you enter an invalid input
	{	cin.clear();
		cin.ignore(999,'\n');
		cout<<"Enter a number:";
		cin>>num;
	}
	return num;
}
