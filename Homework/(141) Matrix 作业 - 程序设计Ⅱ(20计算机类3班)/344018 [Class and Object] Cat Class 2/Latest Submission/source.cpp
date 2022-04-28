#include<iostream>
#include<cstring>
using namespace std;
class Cat
{   public:
        char * name;
   
        Cat(const char * n)
        {   name=new char[strlen(n)+1];
            strcpy(name,n);
        }
        Cat(const Cat & cat)
        {   name=new char[strlen(cat.name)+1];
            strcpy(name,cat.name); 
        }
        Cat & operator = (const Cat & cat)
        {   if(&cat==this)
                return *this;
            delete [] name;
            name=new char[strlen(cat.name)+1];
            strcpy(name,cat.name); 
            return *this;
        }
        const char * get_name() const{return name;}
        ~Cat(){delete [] name;}

};