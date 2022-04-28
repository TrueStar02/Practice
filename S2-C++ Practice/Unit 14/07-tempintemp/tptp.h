#ifndef TPTP_H_
#define TPTP_H_
#include "Tstack.h"
template<template <class T> class Thing>
class Crab
{	private:
		Thing<int> s1;
		Thing<double> s2;
	public:
		Crab(){}
		bool push(int & a,double & b){	return (s1.push(a))&(s2.push(b));}
		bool pop(int &a,double & b){	return (s1.pop(a))&(s2.pop(b));}
};
#endif
