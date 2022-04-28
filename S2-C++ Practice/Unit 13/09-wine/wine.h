#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include<cstring>
using namespace std;
class Port 
{	private:
    	char *brand;
    	char *style; // i.e., tawny, ruby, vintage
   	 	int bottles;
	public:
		Port(const char *br = "none", const char *st = "none", int b = 0);
		Port(const Port &p); // copy constructor
		virtual ~Port() ;
		Port & operator=(const Port &p);
    	Port & operator+=(int b); // adds b to bottles
    	Port & operator-=(int b); // subtracts b from bottles, if available
    	int BottleCount() const { return bottles; }
    	virtual void Show() const;
    	friend ostream & operator<<(ostream &os, const Port &p);
};
class VintagePort : public Port // style necessarily = "vintage"
{	private:
    	char *nickname; // i.e., "The Noble" or "Old Velvet", etc.
    	int year; // vintage year
	public:
		VintagePort();
		VintagePort(const char *br, int b, const char *nn, int y);
		VintagePort(const VintagePort &vp);
		~VintagePort();
		VintagePort & operator=(const VintagePort &vp);
		virtual void Show() const;
		friend ostream & operator<<(ostream &os, const VintagePort &vp);
};
#endif
