#include<iostream> 
#include<stack>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<stdexcept>
#include<cstring>
using namespace std;
class ele
{	public:
		bool isnum;
		double num;
		char ch;
		ele(bool v,double n);
		ele(bool v,char c);
};
class divby0:public logic_error
{	public:
		divby0():logic_error("0 can't be the divisor!"){}
};
class symerr:public logic_error
{	public:
		symerr():logic_error("Misuse the symbols!"){}
};
class chrerr:public logic_error
{	public:
		chrerr():logic_error("Why do you use strange chars?"){}
};
class stkerr:public logic_error
{	public:
		stkerr():logic_error("Stack error!"){}
};
vector<ele> ToRPN(string & s);
double Cauc(vector<ele> RPN);
int main()
{	string str;
	cin>>str;
	vector<ele> RPN;
	double result;
	while(str!="quit")
	{	try
		{	RPN=ToRPN(str);
			result=Cauc(RPN);
			cout<<"Result:"<<result<<endl;
		}
		catch(logic_error & err)
		{	cout<<err.what()<<endl;}
		cin>>str;
	}
	return 0;
}
vector<ele> ToRPN(string & s)
{	stack<char> sym;
	vector<ele> rpn;
	char ** t=NULL;
	string temp="";
	int x;
	for(x=0;x<s.length();x++)
	{	if(isdigit(s[x])||s[x]=='.')
			temp+=s[x];
		else
		{	if(temp!="")
				rpn.push_back(ele(1,strtod(temp.c_str(),t)));
				temp="";
			switch(s[x])
			{	case '(':if(x&&strchr("+-*/(",s[x-1])==NULL)
						{	while(sym.size()&&(sym.top()=='*'||sym.top()=='/'))
							{	rpn.push_back(ele(0,sym.top()));
								sym.pop();
							}
							sym.push('*');
						}		
					sym.push(s[x]);
					break;
				case ')':while(sym.size()&&sym.top()!='(')
						{	rpn.push_back(ele(0,sym.top()));
							sym.pop();
						}
					if(sym.size()&&sym.top()=='(')
						sym.pop();
					break;
				case '*':
				case '/':if(!isdigit(s[x-1])&&s[x-1]!=')')
							throw symerr();
					while(sym.size()&&(sym.top()=='*'||sym.top()=='/'))
					{	rpn.push_back(ele(0,sym.top()));
							sym.pop();
					}
					sym.push(s[x]);
					break;
				case '+':
				case '-':
					if(x==0||s[x-1]=='(')
						rpn.push_back(ele(1,double(0)));
					while(sym.size()&&sym.top()!='(')
					{	rpn.push_back(ele(0,sym.top()));
						sym.pop();
					}
					sym.push(s[x]);
					break;
				default:
					throw chrerr();
			}
		}
	}
	if(temp!="")
		rpn.push_back(ele(1,strtod(temp.c_str(),t)));
	while(sym.size())
	{	if(sym.top()!='(')
			rpn.push_back(ele(0,sym.top()));
		sym.pop();
	}
	return rpn;
}
double Cauc(vector<ele> RPN)
{	vector<ele>::iterator iter;
	stack<double> num;
	double n1,n2;
	for(iter=RPN.begin();iter!=RPN.end();iter++)
	{	if(iter->isnum)
			num.push(iter->num);
		else
		{	if(num.size()<2)
				throw stkerr();
			n1=num.top();
			num.pop();
			n2=num.top();
			num.pop();
			switch(iter->ch)
			{	case '+':num.push(n1+n2);
					break;
				case '-':num.push(n2-n1);
					break;
				case '*':num.push(n1*n2);
					break;
				case '/':if(n1==0)
							throw divby0();
					num.push(n2/n1);
					break;
			}
		}
	}
	if(num.size()!=1)
		throw stkerr();
	return num.top();
}
ele::ele(bool v,double n)
{	if(v==1)
	{	isnum=v;
		num=n;
	}
}
ele::ele(bool v,char c)
{	if(v==0)
	{	isnum=v;
		ch=c;
	}
}
