#include "student.h"
ostream & Student::arr_out(ostream & os) const
{	int lim=valarray<double>::size();
	if(lim>0)
	{	int x;
		for(x=0;x<lim;x++)
			os<<valarray<double>::operator[](x)<<" ";
		os<<endl;
	}
	else
		os<<"No data!\n";
	return os;
}
double Student::Average() const
{	return valarray<double>::sum()/valarray<double>::size();
}
const string & Student::Name() const
{	return (const string &)*this;
}
double & Student::operator[](int i)
{	return valarray<double>::operator[](i);
}
double Student::operator[](int i) const
{	return valarray<double>::operator[](i);
}
istream & operator>>(istream & is,Student & stu)
{	is>>(string &)stu;
	return is;
}
istream & getline(istream & is,Student & stu)
{	getline(is,(string &)stu);
	return is;
}
ostream & operator<<(ostream & os,Student & stu)
{	os<<"Name:"<<(const string &)stu<<endl;
	stu.arr_out(os);
	return os;
}	
