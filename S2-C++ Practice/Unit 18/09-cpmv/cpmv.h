#include<iostream>
using namespace std;
class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };
private:
    Info *pi;
public:
    Cpmv() { pi = nullptr; cout<<"Default Constructor\n"; Display();};
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv &cp);
    Cpmv(Cpmv &&mv);
    ~Cpmv(){delete pi;}
    Cpmv &operator=(const Cpmv&cp);
    Cpmv &operator=(Cpmv&&mv);
    Cpmv operator+(const Cpmv &obj)const;
    void Display()const;
};
Cpmv::Cpmv(std::string q, std::string z)
{	pi=new Info;
	pi->qcode=q;
	pi->zcode=z;
}
Cpmv::Cpmv(const Cpmv &cp)
{	pi=new Info;
	pi->qcode=cp.pi->qcode;
	pi->zcode=cp.pi->zcode;
}
Cpmv::Cpmv(Cpmv &&mv)
{	pi=mv.pi;
	mv.pi=nullptr;
}
Cpmv & Cpmv::operator=(const Cpmv&cp)
{	if(this==&cp)
		return *this;
	pi->qcode=cp.pi->qcode;
	pi->zcode=cp.pi->zcode;
	return *this;
}
Cpmv & Cpmv::operator=(Cpmv&&mv)
{	delete pi;
	pi=mv.pi;
	mv.pi=nullptr;
	return *this;
}
Cpmv Cpmv::operator+(const Cpmv &obj)const
{	return Cpmv(pi->qcode+obj.pi->qcode,pi->zcode+obj.pi->zcode);
}
void Cpmv::Display()const
{	if(pi==nullptr)
		cout<<"Empty object!\n";
	else
	{	cout<<"qcode:"<<(pi->qcode)<<endl;
		cout<<"zcode:"<<(pi->zcode)<<endl;
	}
}
