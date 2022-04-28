#include<iostream>
#include<memory>
using namespace std;
class Report
{	private:
		string str;
	public:
		Report(const string & s):str(s){cout<<"Object Created!\n";}
		~Report(){cout<<"Object Deleted!\n";}
		void comment() const{cout<<str<<endl;}
};
int main(void)
{	cout<<"Now we are trying to use auto_ptr\n";
	{	auto_ptr<Report> ps(new Report("I am auto_ptr"));
		ps->comment();
	}
	cout<<"Now we are trying to use unique_ptr\n";
	{	unique_ptr<Report> ps(new Report("I am unique_ptr"));
		ps->comment();
	}
	cout<<"Now we are trying to use shared_ptr\n";
	{	shared_ptr<Report> ps(new Report("I am shared_ptr"));
		ps->comment();
	}
	return 0;
}
