#include "wrap.h"
#include<functional>
double dub(double x){return 2*x;}
double sqr(double x){return x*x;}
int main()
{	function<double(double)> ef1=dub;
	function<double(double)> ef2=sqr;
	function<double(double)> ef3=Fq(10.0);
	function<double(double)> ef4=Fp(10.0);
	function<double(double)> ef5=[](double x){return x*3.5;};
	cout<<"Function 1:"<<use_f(1.21,ef1)<<endl;
	cout<<"Function 1:"<<use_f(1.21,ef2)<<endl;
	cout<<"Function 1:"<<use_f(1.21,ef3)<<endl;
	cout<<"Function 1:"<<use_f(1.21,ef4)<<endl;
	cout<<"Function 1:"<<use_f(1.21,ef5)<<endl;
	return 0;
}
