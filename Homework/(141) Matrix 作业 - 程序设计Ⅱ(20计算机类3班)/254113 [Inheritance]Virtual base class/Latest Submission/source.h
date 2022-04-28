#include<iostream>
using namespace std;
class base
{		string name;
		int age;
	public:
		base(){}
		void setname(char arr[]){name=arr;}
		void setage(int a){age=a;}
		string getname() const {return name;}
		int getage() const {return age;}
};
class leader:virtual public base
{	private:
		string job;
        string dep;
	public:
		void setjob(char arr[]){job=arr;}
        void setdep(char arr[]){dep=arr;}
        string getjob(){return job;}
        string getdep(){return dep;}
}; 
class engineer:virtual public base
{	private:
		string major;
        string prof;
    public:
    	void setmajor(char arr[]){major=arr;}
        void setprof(char arr[]){prof=arr;}
		string getmajor(){return major;}
        string getprof(){return prof;}
}; 
class chairman:public leader,public engineer
{   private:
        
        
    public:
        //void setname(char arr[]){base::setname(arr);}
        
        
        //void setage(int age){base::setage(age);}
       // string getname() const {return base::getname();}
        //int getage() const {return base::getage();}
       
        
};