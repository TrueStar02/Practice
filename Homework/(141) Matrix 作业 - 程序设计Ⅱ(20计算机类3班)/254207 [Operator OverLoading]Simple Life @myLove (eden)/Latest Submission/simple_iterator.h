#include<iostream>
using namespace std;
class simple_iterator
{   private:
        char * ptr;
    public:
        simple_iterator(){}
        simple_iterator(char * p){ptr=p;}
        simple_iterator operator+(int n){return ptr+n;}
        simple_iterator operator-(int n){return ptr-n;}
        bool operator>(simple_iterator iter){return *ptr>*iter.ptr;}
        bool operator>=(simple_iterator iter){return *ptr>=*iter.ptr;}
        bool operator<(simple_iterator iter){return *ptr<*iter.ptr;}
        bool operator<=(simple_iterator iter){return *ptr<=*iter.ptr;}
        bool operator==(simple_iterator iter){return *ptr==*iter.ptr;}
        bool operator!=(simple_iterator iter){return *ptr!=*iter.ptr;}
        char operator*(){return *ptr;}
        simple_iterator & operator++()
        {   ptr++;
            return *this;
        }
        simple_iterator operator ++(int)
        {   simple_iterator temp=*this;
            ptr++;
            return temp;
        }
         simple_iterator & operator--()
        {   ptr--;
            return *this;
        }
        simple_iterator operator --(int)
        {   simple_iterator temp=*this;
            ptr--;
            return temp;
        }
     simple_iterator prev(){return (*this)-1;}
     simple_iterator next(){return (*this)+1;}
     simple_iterator begin()
     {  char * p=ptr;
        while(p[-1]!='\0')
            p--;
         return simple_iterator(p);
         }
     simple_iterator end()
     {  char * p=ptr;
        while(p[1]!='\0')
            p++;
         return simple_iterator(p);
         }
};