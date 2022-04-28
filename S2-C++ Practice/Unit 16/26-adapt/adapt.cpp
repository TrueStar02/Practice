#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;
void Show(double & d){cout<<d<<" ";}
//template<typename T>
//T & div(const T & x){return divides<T>(x,(T)2);}
int main(void)
{	double arr1[6]={1.3,4.6,7.7,8.6,2.9,5.4};
	double arr2[6]={8.1,5.2,3.4,0.7,2.9,3.4};
	vector<double> v1(arr1,arr1+6);
	vector<double> v2(arr2,arr2+6);
	cout<<"v1:";
	for_each(arr1,arr1+6,Show);
	cout<<endl<<"v2:";
	for_each(v2.begin(),v2.end(),Show);
	vector<double> pl;
	transform(v1.begin(),v1.end(),v2.begin(),back_insert_iterator<vector<double>>(pl),plus<double>());
	cout<<endl<<"Sum:";
	for_each(pl.begin(),pl.end(),Show);
	vector<double> mu;
	transform(v1.begin(),v1.end(),back_insert_iterator<vector<double>>(mu),bind1st(multiplies<double>(),2.5));
	cout<<endl<<"Times:";
	for_each(mu.begin(),mu.end(),Show);
	vector<double> dv;
	transform(v2.begin(),v2.end(),back_insert_iterator<vector<double>>(dv),bind2nd(divides<double>(),2));
	cout<<endl<<"Half:";
	for_each(dv.begin(),dv.end(),Show);
	return 0;
}
