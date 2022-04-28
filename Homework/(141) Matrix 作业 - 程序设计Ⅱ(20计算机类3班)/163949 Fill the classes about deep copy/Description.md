# Fill the classes about deep copy

# Description
A Person class should be implemented, which has two member variables: id, birthDate. You need to add a copy constructor to the Person class, which should perform deep copy.

Note : 
The following code includes the partial implement of the Date and Person classes.You should fill the two classes.


```
class Date { 
public:
    
    Date(int y, int m, int d) { year=y; month=m; day=d; }
    
    int getYear()const { return year; }
    
    void setYear(int y) { year = y; }
private:

    int year, month, day;
};

class Person

{
public:
    
    Person(int id, int year, int month, int day) {
    
        this->id = id;
    
        birthDate = new Date(year, month, day);
    
    }
    
    ~Person() { delete birthDate; }
    
    int getId()const { return id; }
    
    Date* getBirthDate() const{ return birthDate; }
private:

    int id;
    
    Date* birthDate;
};
```
Your submitted source code should include the whole implementation of the Date and Person classes. No `main()` function should be included.

## main函数
```
// framework.cpp
#include <cstdio>
#include "Person.h"

int main()
{
 int id;
 scanf("%d",&id);
    Person person1(id, 1970, 5, 3);
    Person person2(person1);
 if(person1.getBirthDate() == person2.getBirthDate()) printf("Yes\n");
 else printf("No\n");
 return 0;
}
```