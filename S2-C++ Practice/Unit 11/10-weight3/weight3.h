#ifndef WEIGHT3_H_
#define WEIGHT3_H_
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
		operator double();
		void sw_mode(int mo=0);
		friend ostream & operator<<(ostream & os,const Weight & w);
};
#endif
