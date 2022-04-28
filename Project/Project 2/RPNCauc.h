#ifndef RPNCAUC_H_
#define RPNCAUC_H_
#include <vector>
#include <stdexcept>
#include <sstream>
#include <stack>
#include <cctype>
#include "Polynomial.h"
#include "ST.h"
using namespace std;
class ele
{
public:
	bool ispoly;		 //1-polynomial 0-symbol
	Poly p;				 //Store a polynomial
	char ch;			 //Store a symbol
	ele(bool v, Poly p); //if v=1,store a polynomial
	ele(bool v, char c); //if v=0,store a char
};
class symerr : public logic_error
{
public:
	symerr() : logic_error("Misuse the symbols!") {}
};
class chrerr : public logic_error
{
public:
	chrerr() : logic_error("Why do you use strange chars?") {}
};
class stkerr : public logic_error
{
public:
	stkerr() : logic_error("Stack error!") {}
};
class no_found : public logic_error
{
private:
	string key;

public:
	no_found(string k) : key(k), logic_error("Cannot find the key ") {}
	string what();
};
vector<ele> ToRPN(string &t, ST<string, Poly> &s); //Transform a normal expression to RPN
Poly CalcRPN(vector<ele> rpn);					   //Calculate an RPN
ele::ele(bool v, Poly p0)
{
	if (v == 1)
	{
		ispoly = v;
		p = p0;
	}
}
ele::ele(bool v, char c)
{
	if (v == 0)
	{
		ispoly = v;
		ch = c;
	}
}
string no_found::what()
{
	ostringstream strout;
	strout << logic_error::what() << "\"" << key << "\"!";
	return strout.str();
}
vector<ele> ToRPN(string &t, ST<string, Poly> &s)
{
	int x;
	string temp = "";				 //Store the polynomials' name
	stack<char> sym;				 //Store the symbols tempororaly
	vector<ele> rpn;				 //Store the RPN
	for (x = 0; x < t.length(); x++) //Scan the string
	{
		if (isalnum(t[x])) //A part of the name
			temp += t[x];
		else
		{
			if (temp != "") //If there is a polynomial to process
			{
				if (s.contains(temp))				//If the polynimial exists
					rpn.push_back(ele(1, s[temp])); //Push it to the RPN
				else
					throw no_found(temp); //Throw an exception
			}
			temp = "";
			switch (t[x]) //Process symbols
			{
			case '(':
				if (x && strchr("+-*(", t[x - 1]) == NULL) //Add * automatically
				{										   //Process the polynomials such as (p+q)(r+s)
					while (sym.size() && sym.top() == '*')
					{
						rpn.push_back(ele(0, '*'));
						sym.pop();
					}
					sym.push('*');
				}
				sym.push('(');
				break;
			case ')':
				while (sym.size() && sym.top() != '(') //Pop the symbols from the stack
				{
					rpn.push_back(ele(0, sym.top())); //And push them into RPN
					sym.pop();
				}
				if (sym.size() && sym.top() == '(') //Finally pop "("
					sym.pop();
				break;
			case '*':
				if (!isalnum(t[x - 1]) && t[x - 1] != ')' && t[x - 1] != '.') //Avoid such as (*3)
					throw symerr();											  //Throw an exception
				while (sym.size() && sym.top() == '*')						  //Pop the "*"s from the stack
				{
					rpn.push_back(ele(0, '*')); //And push them into RPN
					sym.pop();
				}
				sym.push('*'); //Push the last "*" into the stack
				break;
			case '+':
			case '-':
				if (x == 0 || t[x - 1] == '(')			  //Process the negative symbol such as (-p*q)
					rpn.push_back(ele(1, Poly("(0,0)"))); //Add "0" to RPN automatically
				while (sym.size() && sym.top() != '(')	  //Pop the symbols from the stack
				{
					rpn.push_back(ele(0, sym.top())); //And push them into RPN
					sym.pop();
				}
				sym.push(t[x]); //Push the last symbol into the stack
				break;
			default:			//If there is a strange char
				throw chrerr(); //Throw an excepion
			}
		}
	}
	if (temp != "") //Process the last polynomial if it is there
	{
		if (s.contains(temp))				//If the polynimial exists
			rpn.push_back(ele(1, s[temp])); //Push it to the RPN
		else
			throw no_found(temp); //Throw an excepion
	}
	while (sym.size()) //Process the remaining symbols in the stack
	{
		if (sym.top() != '(') //If you forget the last ")",we can process it
			rpn.push_back(ele(0, sym.top()));
		sym.pop();
	}
	return rpn;
}
Poly CalcRPN(vector<ele> rpn)
{
	vector<ele>::iterator iter; //Declare an iterator
	stack<Poly> num;			//Polynomial stack
	Poly n1, n2;
	for (iter = rpn.begin(); iter != rpn.end(); iter++) //Scan the RPN
	{
		if (iter->ispoly)	   //If it is a polynomial
			num.push(iter->p); //Push it to the stack
		else				   //If it is a symbol
		{
			if (num.size() < 2) //Not enough polynomials
				throw stkerr(); //Throw an exception
			n1 = num.top();		//Pop two polynomials to calculate
			num.pop();
			n2 = num.top();
			num.pop();
			switch (iter->ch)
			{
			case '+':
				num.push(n1 + n2); //Calculate them then push the result back
				break;
			case '-':
				num.push(n2 - n1); //The polynomial to be subscribe
				break;			   //was popped later
			case '*':
				num.push(n1 * n2);
				break;
			}
		}
	}
	if (num.size() != 1) //At last there is only one polynomial in the stack
		throw stkerr();	 //Otherwise throw an exception
	return num.top();	 //Return the result
}
#endif                                                                                                                                                                                                                                                                                                                       