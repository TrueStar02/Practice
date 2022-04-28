#include<iostream>
using namespace std;
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
		//friend ostream & operator<<(ostream & os,Pair<T1,T2> & p);
};
int main(void)
{	Pair<int,double> p1(2,4.5);
	Pair<double> p2(4.7);
	cout<<p1.value1()<<" "<<p1.value2()<<" "<<p2.value1()<<" "<<p2.value2()<<endl;
	p2.value2()=2;
	cout<<p2.value1()<<" "<<p2.value2()<<endl;
}
/*template<class T1,class T2>
ostream & operator<<(ostream & os,Pair<T1,T2> & p)
{	os<<p.a<<" "<<p.b;
	return os;
}
*/
