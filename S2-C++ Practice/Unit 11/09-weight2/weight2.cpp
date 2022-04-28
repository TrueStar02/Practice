#include "weight2.h"
Weight::Weight()
{	kilo=gram=tot_gram=mode=0;
}
Weight::Weight(double n)
{	tot_gram=n;
	kilo=int(tot_gram/1000);
	gram=tot_gram-kilo*1000;
	mode=0;
}
Weight::Weight(int k,double n)
{	kilo=k;
	gram=n;
	tot_gram=1000*kilo+gram;
	mode=2;
}
Weight::~Weight()
{	//destructor
}
void Weight::sw_mode(int mo)
{	switch(mo)
	{	case 0:mode=0;
			cout<<"Default Mode\n";
			break;
		case 1:mode=1;
			cout<<"Interger Gram Mode\n";
			break;
		case 2:mode=2;
			cout<<"Kilo and Gram Mode\n";
			break;
		case 3:mode=3;
			cout<<"Kilo Mode\n";
			break;
		default:cout<<"Invalid Mode!\n";
	}
}
Weight Weight::operator*(double n)const
{	double val=n*tot_gram;
	return Weight(val);
}
Weight Weight::operator/(double n)const
{	double val=tot_gram/n;
	return Weight(val);
}
Weight operator+(const Weight & w1,const Weight & w2)
{	double val=w1.tot_gram+w2.tot_gram;
	return Weight(val);
}
Weight operator-(const Weight & w1,const Weight & w2)
{	double val=w1.tot_gram-w2.tot_gram;
	return Weight(val);
}
bool operator>(const Weight & w1,const Weight & w2)
{	return (w1.tot_gram>w2.tot_gram);
}
bool operator<(const Weight & w1,const Weight & w2)
{	return (w1.tot_gram<w2.tot_gram);
}
bool operator>=(const Weight & w1,const Weight & w2)
{	return (w1.tot_gram>=w2.tot_gram);
}
bool operator<=(const Weight & w1,const Weight & w2)
{	return (w1.tot_gram<=w2.tot_gram);
}
bool operator==(const Weight & w1,const Weight & w2)
{	return (w1.tot_gram==w2.tot_gram);
}
bool operator!=(const Weight & w1,const Weight & w2)
{	return (w1.tot_gram!=w2.tot_gram);
}
ostream & operator<<(ostream & os,const Weight & w)
{	switch(w.mode)
	{	case 0:os<<w.tot_gram<<"gram(s)"<<endl;
			break;
		case 1:os<<int(w.tot_gram)<<"gram(s)"<<endl;
			break;
		case 2:if(w.kilo)
			os<<w.kilo<<"kilo(s) and ";
			os<<w.gram<<"gram(s)"<<endl;	
			break;
		case 3:os<<(w.kilo+w.gram/1000)<<"kilo(s)"<<endl;
			break;
	}
	return os;
}
