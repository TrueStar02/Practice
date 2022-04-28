#include "user.hpp"
#include<cstring> 
Alipay::user::user(const char* u, const char* p)
{   strncpy(username,u,20);
    username[20]='\0';
    strncpy(password,p,20);
    password[20]='\0';
    balance=0;
}
Alipay::user::~user(){}
const char*  Alipay::user::getUsername() const{return username;}
const char*  Alipay::user::getPassword() const{return password;}
const void  Alipay::user::setUsername(const char* u)
{   strncpy(username,u,20);
    username[20]='\0';
}
const void  Alipay::user::setPassword(const char* p)
{   strncpy(password,p,20);
    password[20]='\0';
} 
double  Alipay::user::getBalance(){return balance;}
bool  Alipay::user::withdraw(double amount)
{   if(amount<0)return 0;
    if(amount>balance)return 0;
    balance-=amount;
    return 1;
}
bool  Alipay::user::deposite(double amount)
{   if(amount<0)return 0;
    balance+=amount;
    return 1;
}