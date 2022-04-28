#include<iostream>
#include "Exception.hpp"
#include<cctype>
using namespace std;
class calculator
{   private:
        int sum;
        bool isplus;
        int num;
    public:
        int calculate(const string & t)
        {   int x;
            sum=0;
            isplus=1;
            if(!t.length())
                throw EmptyExpressionException();
            for(x=0;x<t.length();x++)
            {   if(!isdigit(t[x])&&t[x]!='+'&&t[x]!='-') 
                    throw IllegalSymbolException(x);
                if(isdigit(t[x]))
                {   if(x%2)
                        throw MissingOperatorException(x);
                    else
                    {   num=t[x]-48;
                        if(isplus)
                            sum+=num;
                        else
                            sum-=num;
                    }
                }
                else
                {   if(x%2==0)
                        throw MissingOperandException(x);
                    if(t[x]=='+')
                        isplus=1;
                    else
                        isplus=0;
                }
            }
            if(t.length()%2==0)
                throw MissingOperandException(x);
            return sum;
        }


};