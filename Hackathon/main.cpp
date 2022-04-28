#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include "user.h"
using namespace std;
user Guard(fstream & fp);
void Star(void);
char menu0();
char menu1();
char menu2();
void ListActivities(user u,fstream & u_ptr,fstream & a_ptr);
void JoinActivity(user u,fstream & u_ptr,fstream & a_ptr);
void ExitActivity(user u,fstream & u_ptr,fstream & a_ptr);
void SendActivity(user u,fstream & u_ptr,fstream & a_ptr);
//void CancelActivity();
void AddActivity(user u,fstream & u_ptr,fstream & a_ptr);
//void DeleteActivity();
void LoadUsers(user u,fstream & u_ptr,fstream & a_ptr);
void GetDetails(user u,fstream & u_ptr,fstream & a_ptr);
int main()
{   fstream users_ptr;
    fstream activ_ptr;
    user utemp;
    Activity atemp;
    users_ptr.open("users.txt",ios_base::in|ios_base::out|ios_base::binary);
    activ_ptr.open("activities.txt",ios_base::in|ios_base::out|ios_base::binary);
    cout<<activ_ptr.is_open()<<endl;
    users_ptr.read((char *)(&utemp),sizeof(user));
    if(users_ptr.eof())
    {   user admin("Administrator",88888888,"000000          ",0);
        users_ptr.clear();
        users_ptr.seekg(0);
        users_ptr.write((char *)(&admin),sizeof(user));
        users_ptr.seekg(0);
    }
    char ch;
    unsigned int u_pos,a_pos;
    user person=Guard(users_ptr);
    while(person.number)
    {   bool terminate=0;
        while(!terminate)
        {   switch(person.type)
            {   case 0:ch=menu0();
                   break;
                case 1:ch=menu1();
                   break;
                case 2:ch=menu2();
                    break;
            }
            u_pos=users_ptr.tellp();
            a_pos=activ_ptr.tellp();
            switch(ch)
            {   case 'a':ListActivities(person,users_ptr,activ_ptr);
                    break;
                case 'b':JoinActivity(person,users_ptr,activ_ptr);
                    break;
                case 'c':ExitActivity(person,users_ptr,activ_ptr);
                    break;
                case 'd':SendActivity(person,users_ptr,activ_ptr);
                    break;
                //case 'e':CancelActivity();
                //    break;
                case 'f':AddActivity(person,users_ptr,activ_ptr);
                    break;
                //case 'g':DeleteActivity();
                //    break;
                case 'h':LoadUsers(person,users_ptr,activ_ptr);
                    break;
                case 'i':GetDetails(person,users_ptr,activ_ptr);
                    break;
                case 'q':terminate=1;
                    break;
                default:
                    cout<<"Coming Soon~";
            }
            users_ptr.clear();
            activ_ptr.clear();
            users_ptr.seekp(u_pos);
            activ_ptr.seekp(a_pos);
        }
        person=Guard(users_ptr);
    }
}
user Guard(fstream & fp)
{	Star();
	bool flag;//1 means the pasword is right and 0 means exit
	char ch;
	int x;
    int number;
	cout<<"System is locked!\n";
    user t;
    while(1)
    {   fp.clear();
        fp.seekp(0);
        cout<<"Please Enter the user number,0 to quit\n";
        cin>>number;
        if(number)
        {   while(!fp.eof())
            {   fp.read((char *)(&t),sizeof(user));
                if(t.number==number)
                {   fp.seekp(-sizeof(user),ios_base::cur); 
                    break;
                }
            }
            if(t.number==number)
                break;
            cout<<"No found\n";
        }
        else
            memset(&t,1,sizeof(user));
    }
    if(number)
	{   
        cout<<"Enter the password or enter \"quit\" to exit\n";
	    string temp="";
	    while(1)
	    {	temp="";
	    	cout<<"Enter the password:";
	    	setvbuf(stdin,NULL,_IONBF,0);//No buffer
	    	setvbuf(stdout,NULL,_IONBF,0);//No buffer
	    	system("stty -echo");//Linux only.hide the input
	    	while((ch=cin.get())&&ch!=10)//read chars and output *
 	    	{	temp+=ch;
 			    cout.put('*');
 		    }
 		    for(x=temp.length();x<16;x++)//Make sure the string length is 16
 			    temp+=' ';
 		    cout<<endl;
 		    system("stty echo");//Linux only.Cancel the hide of the input
 		    setvbuf(stdin,NULL,_IOFBF,4096);//Full buffer
 		    setvbuf(stdout,NULL,_IOFBF,4096);//Full buffer
            string answer(t.password,t.password+16);
 		    if(temp==answer)//If the password is right
 		    {	flag=1;
                t.activ=new fstream;
                ostringstream strout;
                strout<<t.number<<".txt";
                const char * name=strout.str().c_str();
                t.activ->open(name);
 		    	break;
 		    }
 		    else if(temp=="quit            ")//If you want to quit
 		    {	flag=0;
 		    	break;
 		    }
 		    else//If you're wrong
 		    	cout<<"You're wrong!\n";
 	    }
    }
 	return t;
}
char menu0()
{   Star();
    char v;
    cin.ignore(999,'\n');
    cout<<"Administor Account\n";
    cout<<"Choose the function you need:\n";
    cout<<"A-List Activities\n";
    cout<<"F-Add an Activity\n";
    cout<<"G-Delete an Activity\n";
    cout<<"H-Load users\n";
    cout<<"I-Print the user's information\n";
    cout<<"Q-Quit\n";
    while((v=tolower(cin.get()))&&strchr("afghiq",v)==NULL)
    {   cin.ignore();
        cout<<"Enter A,F,G,H or I!";
    }
    cin.ignore(999,'\n');
    return v;

}
char menu1()
{   Star();
    char v;
    cin.ignore(999,'\n');
    cout<<"Student Account\n";
    cout<<"Choose the function you need:\n";
    cout<<"A-List Activities\n";
    cout<<"B-Join an Activity\n";
    cout<<"C-Exit an Activity\n";
    cout<<"I-Print the user's information\n";
    cout<<"Q-Quit\n";
    while((v=tolower(cin.get()))&&strchr("abciq",v)==NULL)
    {   cin.ignore();
        cout<<"Enter A,B,C or I!";
    }
    cin.ignore(999,'\n');
    return v;
}
char menu2()
{   Star();
    char v;
    cin.ignore(999,'\n');
    cout<<"Organization Account\n";
    cout<<"Choose the function you need:\n";
    cout<<"A-List Activities\n";
    cout<<"D-Send an Activity\n";
    cout<<"E-Cancel an Activity\n";
    cout<<"I-Print the user's information\n";
    cout<<"Q-Quit\n";
    while((v=tolower(cin.get()))&&strchr("adeiq",v)==NULL)
    {   cin.ignore();
        cout<<"Enter A,D,E or I!";
    }
    cin.ignore(999,'\n');
    return v;
}
void ListActivities(user u,fstream & u_ptr,fstream & a_ptr)
{   a_ptr.clear();
    a_ptr.seekg(0);
    Activity temp;
    while(a_ptr.read((char *)(&temp),sizeof(Activity)))
    {   
        temp.print();
    }
    a_ptr.clear();

}
void JoinActivity(user u,fstream & u_ptr,fstream & a_ptr)
{   cout<<"Enter the number of the activity:";
    int n;
    cin>>n;
    cin.ignore(999,'\n');
    if(u.Join(a_ptr,n))
        cout<<"Success!\n";
    else
        cout<<"Failed!\n";
}
void ExitActivity(user u,fstream & u_ptr,fstream & a_ptr)
{   cout<<"Enter the number of the activity:";
    int n;
    cin>>n;
    cin.ignore(999,'\n');
    if(u.Cancel(a_ptr,n))
        cout<<"Success!\n";
    else
        cout<<"Failed!\n";

}
void SendActivity(user u,fstream & u_ptr,fstream & a_ptr)
{   char n[30],index[170];
    int no,lim,s,h;
    cout<<"Enter the name of the activity\n";
    cin.getline(n,30);
    cout<<"Enter the introduction of the activity\n";
    cin.getline(index,170);
    cout<<"Enter the number of the activity:" ;
    cin>>no;
    cout<<"Enter the limit of the activity:";
    cin>>lim;
    cout<<"Enter the sport score of the activity:";
    cin>>s;
    cout<<"Enter the hour of the activity:";
    cin>>h;
    Activity temp(n,index,no,lim,h,s);
    FILE * cre;
    ostringstream strout;
    strout<<no<<".txt";
    const char * name=strout.str().c_str();
    cout<<name<<endl;
    cre=fopen(name,"w");
    fclose(cre);
    temp.user_ptr=new fstream(name,ios_base::in|ios_base::out|ios_base::binary);
    u.SendActivity(temp,a_ptr);
}
//void CancelActivity();
void AddActivity(user u,fstream & u_ptr,fstream & a_ptr)
{   char n[30],index[170];
    int no,lim,s,h;
    cout<<"Enter the name of the activity\n";
    cin.getline(n,30);
    cout<<"Enter the introduction of the activity\n";
    cin.getline(index,170);
    cout<<"Enter the number of the activity:" ;
    cin>>no;
    cout<<"Enter the limit of the activity:";
    cin>>lim;
    cout<<"Enter the sport score of the activity:";
    cin>>s;
    cout<<"Enter the hour of the activity:";
    cin>>h;
    Activity temp(n,index,no,lim,h,s);
    FILE * cre;
    ostringstream strout;
    strout<<no<<".txt";
    const char * name=strout.str().c_str();
    cout<<name<<endl;
    cre=fopen(name,"w");
    fclose(cre);
    temp.user_ptr=new fstream(name,ios_base::in|ios_base::out|ios_base::binary);
    u.AddActivity(temp,a_ptr);

}
//void DeleteActivity();
void LoadUsers(user u,fstream & u_ptr,fstream & a_ptr)
{   string filename;
    cout<<"Enter the filename:";
    cin>>filename;
    ifstream fin;
    FILE * cre;
    fin.open(filename.c_str()); //Try to open the file
	if (!fin.is_open())			//If the file can't be opened
	{
		cout << "Cannot open the file!\n"; //Remind the user
		cin.ignore(999, '\n');
		cout << "Press enter to the previous menu"; //Back to the previous menu
		cin.ignore(999, '\n');
		return;
	}
	cout << "The file " << filename << " is open!\n"; //Tell the user that the file is open
	string username;
    int number;
    string p;
    int type;
    int x;
    user utemp;
    u_ptr.clear();
    u_ptr.seekg(sizeof(user));
    while(fin>>username>>number>>p>>type)
    {   while(p.length()<16)
            p+=' '; 
        utemp=user(username.c_str(),number,p.data(),type);
        u_ptr.write((char *)(&utemp),sizeof(user));
        ostringstream strout;
        strout<<number<<".txt";
        const char * name=strout.str().c_str();
        cout<<name<<endl;
        cre=fopen(name,"w");
        fclose(cre);
    }
	fin.clear();
}
void GetDetails(user u,fstream & u_ptr,fstream & a_ptr)
{   u.GetData(a_ptr);

}
void Star(void)
{	int x;
	for(x=0;x<40;x++)
		cout<<'*';
	cout<<endl;
}
