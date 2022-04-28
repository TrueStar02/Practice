#include<iostream>
using namespace std;
class Useless
{	private:
		int n;
		char * pc;
		static int ct;
		void ShowObject() const;
	public:
		Useless();
		explicit Useless(int k);
		Useless(int k,char ch);
		Useless(const Useless & u);
		Useless(Useless && u);
		~Useless();
		Useless operator+(const Useless & u) const;
		Useless & operator=(const Useless & u);
		Useless & operator=(Useless && u);
		void ShowData() const;
};
int Useless::ct=0;
void Useless::ShowObject() const
{	cout<<"Number of elements:"<<n<<endl;
	cout<<"Address:"<<(void *)pc<<endl;
}
Useless::Useless()
{	ct++;
	n=0;
	pc=nullptr;
}
Useless::Useless(int k):n(k)
{	pc=new char[n];
	ct++;
}
Useless::Useless(int k,char ch):n(k)
{	pc=new char[n];
	ct++;
	int i;
	for(i=0;i<n;i++)
		pc[i]=ch;
}
Useless::Useless(const Useless & u):n(u.n)
{	pc=new char[n];
	ct++;
	int i;
	for(i=0;i<n;i++)
		pc[i]=u.pc[i];
}
Useless::Useless(Useless && u):n(u.n)
{	pc=new char[n];
	ct++;
	pc=u.pc;
	u.pc=nullptr;
	u.n=0;
}
Useless::~Useless()
{	delete [] pc;
	ct--;
}
Useless Useless::operator+(const Useless & u) const
{	Useless nu(n+u.n);
	int i;
	for(i=0;i<n;i++)
		nu.pc[i]=pc[i];
	for(i=0;i<u.n;i++)
		nu.pc[n+i]=u.pc[i];
	return nu;
}
Useless & Useless::operator=(const Useless & u)
{	if(this==&u)
		return *this;
	delete pc;
	n=u.n;
	pc=new char[n];
	int i;
	for(i=0;i<n;i++)
		pc[i]=u.pc[i];
	return *this;
}
Useless & Useless::operator=(Useless && u)
{	n=u.n;
	delete pc;
	pc=u.pc;
	u.pc=nullptr;
	u.n=0;
	return *this;
}
void Useless::ShowData() const
{	if(!n)
		cout<<"(object empty)";
	else
		for(int i=0;i<n;i++)
			cout<<pc[i];
	cout<<endl;
}
