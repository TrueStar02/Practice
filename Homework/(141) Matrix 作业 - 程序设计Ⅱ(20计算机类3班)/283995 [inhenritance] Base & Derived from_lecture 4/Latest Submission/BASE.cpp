#include "BASE.h"
BASE::BASE(int p1, int p2):mem1(p1),mem2(p2){}
	
	int BASE::inc1(){return mem1;}
           int BASE::inc2(){return mem2;}

	void BASE::display(){cout<<"mem1="<<mem1<<",mem2="<<mem2<<endl;}