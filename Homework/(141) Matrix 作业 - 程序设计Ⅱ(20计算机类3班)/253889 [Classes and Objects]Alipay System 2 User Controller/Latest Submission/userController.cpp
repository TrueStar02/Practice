#include "userController.hpp"
#include<cstring>
#include<sstream>
using namespace std;
int Alipay::userController::getUserIndex(const char* username) const
{   int x;
    for(x=0;x<usercount;x++)
        if(!strcmp(users[x]->getUsername(),username))
            return x;
    return -1;
}
Alipay::userController::userController(double i):interest_rate(i),usercount(0)
{   int x;
    usercount=0;
    for(x=0;x<10000;x++)
        users[x]=NULL;
}
Alipay::userController::~userController()
{   int x;
    for(x=0;x<usercount;x++)
       delete users[x];
}
bool Alipay::userController::createUser(const char* username, const char* password)
{   if(usercount==10000)return 0;
    if(strlen(username)<6||strlen(username)>20)return 0;
    if(strlen(password)<8||strlen(password)>20)return 0;
    users[usercount]=new user(username,password);
    usercount++;
    return 1;
}
bool Alipay::userController::deposite(const char* username, double amount)
{   int index;
    if((index=getUserIndex(username))==-1)return 0;
    return users[index]->deposite(amount);
   
}
bool Alipay::userController::withdraw(const char* username, double amount)
{    int index;
    if((index=getUserIndex(username))==-1)return 0;
    return users[index]->withdraw(amount);
}
std::string Alipay::userController::getUserInfoByName(const char* username) const
{   int index,x;
    ostringstream strout;
    if((index=getUserIndex(username))==-1)return string("No such user!");
   
   strout<<"username:";
    strout<<users[index]->getUsername();
    strout<<"\npassword:";
    
    for(x=0;x<9;x++)
        strout<<'*';
    
    strout<<"\nbalance:";
    strout<<users[index]->getBalance();
    return strout.str();
}
int Alipay::userController::getUserCount(void) const{return usercount;}
bool Alipay::userController::removeUserByUsername(const char* username)
{   int x,index; 
    if((index=getUserIndex(username))==-1)return 0;
    delete users[index];
    for(x=index+1;x<usercount;x++)
        users[x-1]=users[x];
    users[usercount-1]=NULL;
    usercount--;
    return 1;
}
bool Alipay::userController::setInterest(double interest)
{   if(interest<=0)return 0;
    interest_rate=interest;
    return 1;
}
void Alipay::userController::payInterest(void)
{   int x;
    for(x=0;x<usercount;x++)
        users[x]->deposite(users[x]->getBalance()*(interest_rate));
}

