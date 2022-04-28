#include "SingleDog.h"
#include<cstring>
int SingleDog::count_=0;
SingleDog::SingleDog(int id, const char* name):id_(id)
{   name_=new char[strlen(name)+1];
    strcpy(name_,name);
    count_++;
}

    //copy constructor
    SingleDog::SingleDog(const SingleDog &other):id_(other.id_)
    {   name_=new char[strlen(other.name_)+1];
        strcpy(name_,other.name_);
        count_++;
    }

    //desctructor
    SingleDog::~SingleDog()
    {   delete [] name_;
         count_--;
    }

    //return the count of single dog
   int SingleDog::getCount()
   {
       return count_;
   }