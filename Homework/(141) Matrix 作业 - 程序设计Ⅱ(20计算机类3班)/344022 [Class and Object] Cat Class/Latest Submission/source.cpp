#include<iostream>
using namespace std;
class Cat
{   private:
        string name;
        int age;
    public:
        int get_age() const{return age;}
        string get_name() const{return name;}
        void set_age(int a){age=a;}
        void set_name(const string & n){name=n;} 
};