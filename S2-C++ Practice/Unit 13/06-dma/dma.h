#ifndef DMA_H_
#define DMA_H_
#include<iostream>
#include<cstring>
using namespace std;
class baseDMA
{	private:
		char *label;
		int rating;
	public:
		baseDMA(const char * str="Null",int r=0);
		baseDMA(const baseDMA & b);
		virtual ~baseDMA();
		baseDMA & operator=(const baseDMA & b);
		friend ostream & operator<<(ostream & os,const baseDMA & b);
};
class hasDMA:public baseDMA
{	private:
		char *style;
	public:
		hasDMA(const char * sty="None",const char * str="Null",int r=0);
		hasDMA(const char * sty,const baseDMA & b);
		hasDMA(const hasDMA &h);
		~hasDMA();
		hasDMA & operator=(const hasDMA & h);
		friend ostream & operator<<(ostream & os,const hasDMA & h);
};
#endif
