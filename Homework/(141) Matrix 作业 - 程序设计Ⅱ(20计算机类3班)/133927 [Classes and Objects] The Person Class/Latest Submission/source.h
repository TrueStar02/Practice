class Date
{
    public:
        Date(int newYear,int newMonth,int newDay):year(newYear),month(newMonth),day(newDay){}
        int getYear(){return year;}
        void setYear(int newYear){year=newYear;}
        int getMonth(){return month;}
        int getDay(){return day;}
        void setMonth(int Month){month=Month;}
        void setDay(int Day){day=Day;}

  private:
        int year;
        int month;
        int day;
};

class Person
{
public:
  Person(int id, int year1, int month1, int day1)
  {     this->id=id;
        birthDate=new Date(year1,month1,day1);
        numberOfObjects++;

  }
  Person(const Person & p)
  {     id=p.id;
        birthDate=new Date(p.birthDate->getYear(),p.birthDate->getMonth(),p.birthDate->getDay());
        numberOfObjects++;
  }
  ~Person(){delete birthDate; numberOfObjects--;}
  int getId(){return id;}
  Date * getBirthDate(){return birthDate;}
  static int getNumberOfObjects(); //return the number of Person objects 
 
private:
  int id;
  Date *birthDate; 
  static int numberOfObjects; //count the number of Person objects
};
int Person::numberOfObjects=0;
int Person::getNumberOfObjects(){return numberOfObjects;}