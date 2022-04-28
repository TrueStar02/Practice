#ifndef WEIGHT_H_
#define WEIGHT_H_
#include<iostream>
using namespace std;
class Weight
{	private:	
		int kilo;
		double gram;
		double tot_gram;
		int mode;//0~default 1~int gram 2~kilo&gram 3~kilo
	public:
		Weight();
		Weight(double n);
		Weight(int k,double n);
		~Weight();
		void sw_mode(int mo=0);
		Weight operator*(double n)const;
		Weight operator/(double n)const;
		friend Weight operator+(const Weight & w1,const Weight & w2);
		friend Weight operator-(const Weight & w1,const Weight & w2);
		friend Weight operator*(double n,const Weight & w){return w*(n);}
		friend bool operator>(const Weight & w1,const Weight & w2);
		friend bool operator<(const Weight & w1,const Weight & w2);
		friend bool operator>=(const Weight & w1,const Weight & w2);
		friend bool operator<=(const Weight & w1,const Weight & w2);
		friend bool operator==(const Weight & w1,const Weight & w2);
		friend bool operator!=(const Weight & w1,const Weight & w2);
		friend ostream & operator<<(ostream & os,const Weight & w);
};
#endif
