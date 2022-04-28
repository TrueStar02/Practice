#include "user.hpp"
#include <string>
#include <cstring>
using namespace alipay;
using namespace std;

  inline bool User::verifyPasswordFormat(const std::string &_password)
  {    
      int mark=1;
      int len = _password.length();

      if(len>=8&&len<=20) mark++;
      else return 0;

      for(int i=0;i<len;i++)
      {
        if((_password[i]>=48&&_password[i]<=57)||(_password[i]>=65&&_password[i]<=122)) mark++;
        else return 0;
      }
      return 1;
  }
  inline bool User::verifyUsernameFormat(const std::string &_username)
  {
     int mark=1;
      int len = _username.length();
      if(len>=6&&len<=20) mark++;
      else return 0;
      for(int i=0;i<len;i++)
      {
        if((_username[i]>=48&&_username[i]<=57)||(_username[i]>=65&&_username[i]<=122)) mark++;
        else return 0;
      }
      return mark;
  }
  inline bool User::verifyPhoneFormat(const std::string &_phone)
  {
    int len = _phone.length();
    if(len!=13) return 0;
    for(int i=0;i<len;i++)
    {
      if(_phone[i]<48||_phone[i]>57) return 0;
    }
    return 1;
  }
 
 
  bool User::setUsername(const char *_username)
  {
    if(verifyUsernameFormat(_username))
    {
      username=_username;
      return 1;
    }
    else return 0;
  }
  bool User::setPassword(const char *new_password, const char *old_password)
  {
    if(password==old_password&&verifyPasswordFormat(new_password))
    {   this->password=new_password;
        return 1;
    }
    return 0;
  }
  bool User::setPhone(const char *new_phone)
  {
    if(verifyPhoneFormat(new_phone))
    {
      phone=new_phone;
      return 1;
    }
    else return 0;
  }
  bool User::setGender(Gender::Gender _gender)
  {
    if(_gender!=2) {gender=_gender; return 1;}
    else return 0;
  }
 
  std::string User::getUsername(void)
  {
    return username;
  }
  std::string User::getPhone(void)
  {
    return phone;
  }
  alipay::Gender::Gender User::getGender(void)
  {
    return gender;
  }
  
  // if passowrd is in correct, return -1
  long long int User::getMoneyAmount(const char *_password)
  {
    string t1(_password);
    if(t1==password) return balance;
    else return -1;
  }
  bool User::deposit(long long int amount)
  { 
    if(amount>0)
     {
       balance+=amount;
     return 1;
     }
     else return 0;
  }
  bool User::withdraw(long long int amount, const char *_password)
  {
    string t1(_password);
    if(t1==password&&amount>0&&balance>=amount) {balance-=amount; return 1;}
    else return 0;
  }