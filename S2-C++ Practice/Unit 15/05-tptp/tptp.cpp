#include<iostream>
using namespace std;
template<class T>
class beta
{	private:
		template<class V>
		class hold
		{	private:
				V val;
			public:
				hold(V v=0):val(v){}
				void show() const{cout<<val<<endl;}
				V & Value(){return val;}
		};
		hold<int> i;
		hold<T> t;
	public:
		beta(T t0,int i0):t(t0),i(i0){}
		template<typename U>
		U blab(U v,T t2){return (i.Value()+t.Value())*v/t2;}
		void Show() const{i.show();t.show();}
};
int main(void)
{	beta<double> guy(3.5,3);
	cout << "T was set to double\n";
    guy.Show();
    cout << "V was set to T, which is double, then V was set to int\n";
    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n";
    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n";
    cout << "Done\n";
    return 0;
}
