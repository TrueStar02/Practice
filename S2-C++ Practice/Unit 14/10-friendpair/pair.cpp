#include<iostream>
using namespace std;
template<typename T>
ostream & operator<<(ostream & os,T & t);
template<class T1,class T2=int>
class Pair
{	private:
		T1 a;
		T2 b;
	public:
		explicit Pair(T1 x=0,T2 y=0){a=x;b=y;}
		T1 & value1(){return a;}
		T2 & value2(){return b;}
		T1 value1() const{return a;}
		T2 value2() const{return b;}
		friend ostream & operator<< <Pair<T1,T2>> (ostream & os,Pair<T1,T2> & p);
};
template<typename T>
ostream & operator<<(ostream & os,T & t)
{	os<<(t.value1());
	os.put(' ');
	os<<(t.value2());
	return os;
}
int main(void)
{	Pair<int,double> p1(2,4.5);
	Pair<double> p2(4.7);
	cout<<p1;
	cout.put(' ');
	cout<<p2<<endl;
	p2.value2()=2;
	cout<<p2<<endl;
}
