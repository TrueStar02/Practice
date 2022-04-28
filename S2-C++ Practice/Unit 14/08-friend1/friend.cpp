#include<iostream>
using namespace std;
template<typename T>
class Num
{	private:
		T n;
		static int ct;
	public:
		Num(T x=0):n(x){ct++;}
		~Num(){ct--;}
		friend void Show(const Num<T> & num);
		friend void count() ;
};
void count() 
{	cout<<"int:"<<Num<int>::ct<<"   double:"<<Num<double>::ct<<endl;
}
template<typename T>
int Num<T>::ct=0;
int main(void)
{	Num<int> i(3);
	Num<double> d=1.5;
	Show(i);
	Show(d);
	cout<<endl;
	count();
	return 0;
}
void Show(const Num<int> & num)
{	cout<<num.n<<" ";
}
void Show(const Num<double> & num)
{	cout<<num.n<<" ";
}

