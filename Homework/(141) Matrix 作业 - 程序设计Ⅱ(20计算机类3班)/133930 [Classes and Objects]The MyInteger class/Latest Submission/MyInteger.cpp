#include<cstdlib>
#include "MyInteger.hpp"
MyInteger::MyInteger(int x):value(x){}
    int MyInteger::getValue() const{return value;}
    bool MyInteger::isEven() const{return !(value%2);}
    bool MyInteger::isOdd() const{return value%2;}
    bool MyInteger::isPrime() const
    {  if(value==1||!value)return 0;
         for(int x=2;x*x<=value;x++)
            if(value%x==0)
                return 0;
        return 1;

    }
 bool MyInteger::isEven(int x){return !(x%2);}
   bool MyInteger::isOdd(int x){return x%2;}
    bool MyInteger::isPrime(int y)
    {   if(y==1||!y)return 0;
        for(int x=2;x*x<=y;x++)
            if(y%x==0)
                return 0;
        return 1;

    }
  bool MyInteger::isEven(const MyInteger& x){return !(x.value%2);}    
   bool MyInteger::isOdd(const MyInteger&x){return x.value%2;}
    bool MyInteger::isPrime(const MyInteger&y)
    { if(y.value==1||!y.value)return 0;
        for(int x=2;x*x<=y.value;x++)
            if(y.value%x==0)
                return 0;
        return 1;

    }
    bool MyInteger::equals(int x){return x==value;}
    bool MyInteger::equals(const MyInteger& x){return value==x.value;}
    int MyInteger::parseInt(const std::string&s)
    {   char ** p=NULL;
            return strtol(s.c_str(),p,10);

    }