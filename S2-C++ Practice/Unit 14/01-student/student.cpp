#include "student.h"
ostream & Student::arr_out(ostream & os) const
{	int lim=scores.size();
	if(lim>0)
	{	int x;
		for(x=0;x<lim;x++)
			os<<scores[x]<<" ";
		os<<endl;
	}
	else
		os<<"No data!\n";
	return os;
}
double Student::Average() const
{	if(score.sum()>0)
		return scores.sum()/scores.size();
	else
		return 0;
}
const string & Student::Name() const
{	return name;
}
double & Student::operator[](int i)
{	return scores[i];
}
double Student::operator[](int i) const
{	return scores[i];
}
istream & operator>>(istream & is,Student & stu)
{	is>>stu.name;
	return is;
}
istream & getline(istream & is,Student & stu)
{	getline(is,stu.name);
	return is;
}
ostream & operator<<(ostream & os,Student & stu)
{	os<<"Name:"<<stu.name<<endl;
	stu.arr_out(os);
	return os;
}	
