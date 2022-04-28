#include<iostream>
using namespace std;
template<typename T>
class Num
{	private:
		T n;
	public:
		Num(T x=0):n(x){}
		template<typename U,typename V>
		friend void Show(const U & u,const V & v);
};
int main(void)
{	Num<int> i(3);
	Num<double> d=1.5;
	Show(i,d);
	return 0;
}
template<typename U,typename V>
void Show(const U & u,const V & v)
{	cout<<u.n<<" "<<v.n<<endl;
}
