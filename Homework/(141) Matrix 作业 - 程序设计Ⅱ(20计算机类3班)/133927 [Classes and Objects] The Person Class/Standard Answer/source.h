// Problem#: 17681
// Submission#: 4648138
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>

using namespace std;

class Date
{
    public:
        Date(int newYear,int newMonth,int newDay);
        int getYear();
        void setYear(int newYear);
        int getMonth();
        int getDay();
        void setMonth(int Month);
        void setDay(int Day);

  private:
        int year;
        int month;
        int day;
};

class Person
{
    public:
        Person(int id,int year,int month,int day);
        Person(Person &);
        ~Person();
        int getId();
        Date * getBirthDate();
        static int getNumberOfObjects();
    private:
        int id;
        Date *birthDate;
        static int numberOfObjects;
};

int Person::numberOfObjects = 0;

Date::Date(int newYear,int newMonth,int newDay)
{
    year = newYear;
    month = newMonth;
    day = newDay;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}


void Date::setYear(int newYear)
{
    year = newYear;
}
void Date::setMonth(int Month)
{
    month = Month;
}
void Date::setDay(int Day)
{
    day = Day;
}
Person::Person(int _id,int _year,int _month,int _day)
{
    id = _id;
    birthDate = new Date(_year,_month,_day);
    numberOfObjects ++;
}
Person::Person(Person & guy)
{
    id = guy.id;
    birthDate = new Date(guy.birthDate->getYear(),guy.birthDate->getMonth(),guy.birthDate->getDay());
    numberOfObjects++;
}

Person::~Person()
{
    delete birthDate;
    numberOfObjects--;
}

int Person::getId()
{
    return id;
}

Date * Person::getBirthDate()
{
    return birthDate;
}

int Person::getNumberOfObjects()
{
    return numberOfObjects;
}                                 
