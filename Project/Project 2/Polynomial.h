#ifndef POLYNOMIAL_H_
#define POLYNORIAL_H_
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;
const double eps = 1e-8;			 //Using "==" to judge whether a float number equals to 0 is undependable
class bad_index : public logic_error //an exception class to show the index is negative
{
public:
	bad_index() : logic_error("Index shouldn't be negative!") {}
};
class illegal_input : public logic_error //an exception class to show the input is illegal
{
public:
	illegal_input() : logic_error("The input is illegal!") {}
};
class used_name : public logic_error //an exception class to show the input is illegal
{
public:
	used_name() : logic_error("The name is used!") {}
};
class Mono //Mono class to present a monomial
{
public:
	double coeff;																	 //Coefficient
	int index;																		 //index,it should be a nature number
	Mono(double c, int i) : coeff(c), index(i) {}									 //Constructor
	Mono operator*(const Mono &p) { return Mono(coeff * p.coeff, index + p.index); } //Overloaded operator*,to simplify class Poly's operator*
};
class Poly //Poly class.
{
private:
	vector<Mono> data;			   //A polynomial is the combination of some monomials,using "vector" to add or delete monomials easily
	double mypow(double x, int y); //to calculate power quickly
public:
	Poly() {}
	Poly(const string &s);									//default constructor
	Poly operator+(const Poly &p);							//Overloaded operator+
	Poly operator-(const Poly &p);							//Overloaded operator-
	Poly operator*(const Poly &p);							//Overloaded operator*
	double value(double x);									//Set an x to get the value
	Poly diff(void);										//Get the derivative of a polynomial
	Poly intg(double c = 0);								//Get the integral of one polynomial
	bool empty(void) { return !data.size(); }				//To know whether the polynomial is 0
	void clear(void) { data.clear(); }						//Clear the polynomial
	void tofile(ostream &os);								//Write polynomials to a file
	friend ostream &operator<<(ostream &os, const Poly &p); //Output a polynomial
};
double Poly::mypow(double x, int y)
{
	double r = 1;
	int z;
	for (z = 1; z <= y; z++)
		r *= x;
	return r;
}
Poly::Poly(const string &s)
{
	int x;
	double c;
	int i;
	char left, comma, right;
	istringstream sin(s); //create an istringstream object to process the string
	while (!sin.eof())
	{
		left = comma = right = 0;
		sin >> left >> c >> comma >> i >> right; //read a monomial from the string
		if (sin.fail() && !sin.eof())			 //If the input is illegal,throw exception
			throw illegal_input();
		if (left != '(' || comma != ',' || right != ')')
			if (left == 0 && comma == 0) //This is not an error
				continue;
			else
				throw illegal_input();
		if (i < 0) //If the index is negative,throw exception
			throw bad_index();
		if (c < eps && c > -eps) //if the coefficient is 0,ignore it
			continue;
		for (x = 0; x < data.size(); x++) //As insertion sort
			if (data[x].index <= i)
				break;
		if (x < data.size() && data[x].index == i) //The same index
		{
			data[x].coeff += c;
			if (data[x].coeff < eps && data[x].coeff > -eps) //If the coefficient is 0
				data.erase(data.begin() + x);				 //Delete it
		}
		else //Insert the monomial
		{
			Mono m(c, i);
			data.insert(data.begin() + x, m);
		}
	}
}
Poly Poly::operator+(const Poly &p)
{
	Poly temp = p;
	int x, y = 0;
	for (x = 0; x < data.size(); x++)
	{
		for (; y < temp.data.size(); y++) //Search the position to insert
		{
			if (data[x].index >= temp.data[y].index)
				break;
		}
		if (temp.data.size() > y && data[x].index == temp.data[y].index) //If the indexes are same
		{
			temp.data[y].coeff += data[x].coeff;
			if (temp.data[y].coeff < eps && temp.data[y].coeff > -eps) //If the coefficient is 0
				temp.data.erase(temp.data.begin() + y);				   //Delete it
		}
		else												  //If no same index
			temp.data.insert(temp.data.begin() + y, data[x]); //Insert the monomial
	}
	return temp;
}
Poly Poly::operator-(const Poly &p) //Using operator+ to calculate operator-
{
	Poly temp = p;
	int x;
	for (x = 0; x < temp.data.size(); x++) //Get the opposite polynomial
		temp.data[x].coeff = -temp.data[x].coeff;
	return (*this) + temp; //a-b=a+(-b)
}
Poly Poly::operator*(const Poly &p)
{
	Poly temp;
	int x, y, z;
	for (x = 0; x < data.size(); x++)
		for (y = 0; y < p.data.size(); y++)
		{
			Mono m = data[x] * p.data[y]; //calculate monomial multiply
			for (z = 0; z < temp.data.size(); z++)
			{
				if (m.index >= temp.data[z].index) //Find where to insert
					break;
			}
			if (z < temp.data.size() && m.index == temp.data[z].index) //If the indexes are same
			{
				temp.data[z].coeff += m.coeff;
				if (temp.data[z].coeff < eps && temp.data[z].coeff > -eps) //If the coefficient is 0
					temp.data.erase(temp.data.begin() + z);				   //Delete it
			}
			else											//If no same index
				temp.data.insert(temp.data.begin() + z, m); //Insert the monomial
		}
	return temp;
}
double Poly::value(double x)
{
	double s = 0; //Initialization
	int y;
	for (y = 0; y < data.size(); y++)
		s += data[y].coeff * mypow(x, data[y].index); //Add every value of the monomial
	return s;
}
Poly Poly::diff(void)
{
	int x;
	Poly temp = *this;
	for (x = 0; x < temp.data.size(); x++)
	{
		if (temp.data[x].index) //if the monomial's index!=0,calculate
		{
			temp.data[x].coeff *= temp.data[x].index;
			temp.data[x].index--;
		}
		else //if the monomial's index=0,delete it
		{
			temp.data.erase(temp.data.begin() + x);
			x--;
		}
	}
	return temp;
}
Poly Poly::intg(double c)
{
	int x;
	Poly temp = *this;
	for (x = 0; x < temp.data.size(); x++) //Integral
	{
		temp.data[x].index++;
		temp.data[x].coeff /= temp.data[x].index;
	}
	if (c > eps || c < -eps) //add the constant
		temp.data.push_back(Mono(c, 0));
	return temp;
}
void Poly::tofile(ostream &os)
{
	int x;
	if (data.size() == 0) //If the polynomial==0
		os << "(0,0)" << endl;
	else
	{
		for (x = 0; x < data.size(); x++) //Output it as input
			os << "(" << data[x].coeff << "," << data[x].index << ")";
		os << endl;
	}
}
ostream &operator<<(ostream &os, const Poly &p)
{
	int x;
	if (p.data.size() == 0) //If the polynomial==0
		os << 0;
	else
		for (x = 0; x < p.data.size(); x++) //Output it an standard
		{
			if (x && p.data[x].coeff > eps) //To prevent such as +6x-9
				os << "+";
			if ((p.data[x].coeff != -1 && p.data[x].coeff != 1) || !p.data[x].index) //To prevent such as 3x^2+1x+6
				cout << p.data[x].coeff;
			else if (p.data[x].coeff == -1)
				cout << "-";
			if (p.data[x].index)
				os << "x";
			if (p.data[x].index > 1)
				os << "^" << p.data[x].index;
		}
	return os;
}
#endif
