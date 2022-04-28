#include<iostream>
using namespace std;
template<typename T,typename F>
T use_f(T v,F f)
{	static int count=0;
	count++;
	cout<<"count:"<<count<<", &count:"<<&count<<", value:";
	return f(v);
}
class Fp
{	private:
		double z;
	public:
		Fp(double x=1.0):z(x){}
		double operator()(double p){return z*p;}
};
class Fq
{	private:
		double z;
	public:
		Fq(double x=1.0):z(x){}
		double operator()(double q){return z+q;}
};
