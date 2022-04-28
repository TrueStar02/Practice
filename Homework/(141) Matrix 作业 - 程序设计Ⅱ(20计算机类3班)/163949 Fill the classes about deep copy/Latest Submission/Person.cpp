#include "Person.h"
       Date::Date(int newYear,int newMonth,int newDay):year(newYear),month(newMonth),day(newDay){}
        int  Date::getYear()const{return year;}
        void  Date::setYear(int newYear){year=newYear;}
        int  Date::getMonth()const{return month;}
        int  Date::getDay()const{return day;}
        void  Date::setMonth(int Month){month=Month;}
        void  Date::setDay(int Day){day=Day;}




  Person::Person(int id, int year1, int month1, int day1)
  {     this->id=id;
        birthDate=new Date(year1,month1,day1);
        

  }
   Person::Person(Person & p)
  {     id=p.id;
        birthDate=new Date(p.birthDate->getYear(),p.birthDate->getMonth(),p.birthDate->getDay());
        
  }
   Person::~Person(){delete birthDate; }
  int  Person::getId(){return id;}
  Date *  Person::getBirthDate(){return birthDate;}

