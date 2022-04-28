#ifndef SALES_H_
#define SALES_H_
#include<iostream>
#include<stdexcept>
using namespace std;
class Sales
{	private:
		double gross[12];
		int year;
	public:
		class bad_index:public logic_error
		{	private:
				int bi;
			public:
				explicit bad_index(int ix,const string & s="Index error in Sales object\n"):logic_error(s),bi(ix){}
				int bi_val() const{return bi;}
				virtual ~bad_index() throw() {}
		};
		explicit Sales(int yy=0);
		Sales(int yy,const double *gr,int n);
		virtual ~Sales() {}
		int Year() const{return year;}
		virtual double operator[](int i)const;
		virtual double & operator[](int i);
};
class LabelSales:public Sales
{	private:
		string label;
	public:
		class nbad_index:public Sales::bad_index
		{	private:
				string lbl;
			public:
				nbad_index(const string & lb,int ix,const string & s="Index error in Sales object\n"):bad_index(ix,s),lbl(lb){}
				const string & label_val() const {return lbl;}
				virtual ~nbad_index() throw() {}
		};
		explicit LabelSales(const string & lb="None",int yy=0):Sales(yy),label(lb){}
		LabelSales(const string & lb,int yy,const double *gr,int n):Sales(yy,gr,n),label(lb){}
		virtual ~LabelSales() {}
		const string & Label() const{return label;}
		virtual double operator[](int i)const;
		virtual double & operator[](int i);
};
#endif
