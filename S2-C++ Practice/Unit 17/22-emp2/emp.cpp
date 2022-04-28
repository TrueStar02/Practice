#include "emp.h"
abstr_emp::abstr_emp():fname("Anonymous"),lname("Null"),job("No Job"){}
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,const std::string & j):fname(fn),lname(ln),job(j){}
void abstr_emp::ShowAll() const
{	cout<<"Name:"<<(*this)<<endl;
	cout<<"Job:"<<job<<endl;
}
void abstr_emp::SetAll()
{	cout<<"Enter the first name:";
	getline(cin,fname);
	cout<<"Enter the last name:";
	getline(cin,lname);
	cout<<"Enter his/her job:";
	getline(cin,job);
}
void abstr_emp::Pure(ostream & os)const
{	os<<fname<<endl;
	os<<lname<<endl;
	os<<job<<endl;
}
abstr_emp::~abstr_emp(){}
ostream & operator<<(std::ostream & os, const abstr_emp & e)
{	cout<<e.fname<<" "<<e.lname;
	return os;
}
employee::employee():abstr_emp(){}
employee::employee(const std::string & fn, const std::string & ln,const std::string & j):abstr_emp(fn,ln,j){}
void employee::ShowAll() const
{	abstr_emp::ShowAll();
}
void employee::SetAll()
{	abstr_emp::SetAll();
}
void employee::Pure(ostream & os) const
{	os<<"1\n";
	abstr_emp::Pure(os);
}
manager::manager():abstr_emp(),inchargeof(0){}
manager::manager(const std::string & fn, const std::string & ln,const std::string & j, int ico):abstr_emp(fn,ln,j),inchargeof(ico){}
manager::manager(const abstr_emp & e, int ico):abstr_emp(e),inchargeof(ico){}
manager::manager (const manager & m):abstr_emp(m),inchargeof(m.inchargeof){}
void manager::ShowAll() const
{	abstr_emp::ShowAll();
	cout<<"In Charge Of:"<<InChargeOf()<<endl;
}
void manager::SetAll()
{	abstr_emp::SetAll();
	cout<<"In Charge Of:";
	cin>>InChargeOf();
	while(cin.get()!='\n')
		continue;
}
void manager::Pure(ostream & os) const
{	os<<"2\n";
	abstr_emp::Pure(os);
	os<<InChargeOf()<<endl;
}
fink::fink():abstr_emp(),reportsto("Null"){}
fink::fink(const std::string & fn, const std::string & ln,const std::string & j, const std::string & rpo):abstr_emp(fn,ln,j),reportsto(rpo){}
fink::fink(const abstr_emp & e, const std::string & rpo):abstr_emp(e),reportsto(rpo){}
fink::fink(const fink & e):abstr_emp(e),reportsto(e.reportsto){}
void fink::ShowAll() const
{	abstr_emp::ShowAll();
	cout<<"Reports to:"<<ReportsTo()<<endl;
}
void fink::SetAll()
{	abstr_emp::SetAll();
	cout<<"Reports to:";
	cin>>ReportsTo();
}
void fink::Pure(ostream & os) const
{	os<<"3\n";
	abstr_emp::Pure(os);
	os<<ReportsTo()<<endl;
}
highfink::highfink():abstr_emp(),manager(),fink(){}
highfink::highfink(const std::string & fn, const std::string & ln,const std::string & j, const std::string & rpo, int ico):abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo){}
highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico):abstr_emp(e),manager(e,ico),fink(e,rpo){}
highfink::highfink(const fink & f, int ico):abstr_emp(f),manager(f,ico),fink(f){}
highfink::highfink(const manager & m, const std::string & rpo):abstr_emp(m),manager(m),fink(m,rpo){}
highfink::highfink(const highfink & h):abstr_emp(h),manager(h),fink(h){}
void highfink::ShowAll() const
{	abstr_emp::ShowAll();
	cout<<"In Charge Of:"<<InChargeOf()<<endl;
	cout<<"Reports to:"<<ReportsTo()<<endl;
}
void highfink::SetAll()
{	abstr_emp::SetAll();
	cout<<"In Charge Of:";
	cin>>InChargeOf();
	while(cin.get()!='\n')
		continue;
	cout<<"Reports to:";
	cin>>ReportsTo();
}
void highfink::Pure(ostream & os) const
{	os<<"4\n";
	abstr_emp::Pure(os);
	os<<InChargeOf()<<endl;
	os<<ReportsTo()<<endl;
}
