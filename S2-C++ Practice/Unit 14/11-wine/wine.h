#ifndef WINE_H_
#define WINE_H_
#include<iostream>
#include<valarray>
using namespace std;
template<class T1,class T2=int>
class Pair
{	private:
		T1 a;
		T2 b;
	public:
		explicit Pair(const T1 & x,const T2 & y):a(x),b(y){}
		T1 & value1(){return a;}
		T2 & value2(){return b;}
		T1 value1() const{return a;}
		T2 value2() const{return b;}
};
class Wine
{	private:
		string name;
		Pair<valarray<int>,valarray<int>> details;
	public:
		Wine(const char *l,int y,const int yr[],const int bot[]):name(l),details(valarray<int>(yr,y),valarray<int>(bot,y)){}
		Wine(const char *l,int y):name(l),details(valarray<int>(y),valarray<int>(y)){}
		void GetBottles();
		int sum() const{return details.value2().sum();}
		string & Label(){return name;}
		void Show() const;
};
#endif
