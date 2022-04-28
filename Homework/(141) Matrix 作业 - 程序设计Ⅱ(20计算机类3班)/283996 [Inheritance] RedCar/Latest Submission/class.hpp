#include<iostream>
using namespace std;
class Wheel
{   public:
        Wheel(){cout<<"Construct a wheel\n";}
};
class Car
{   
    public:
        Car(){cout<<"Construct a car\n";}
};
class RedCar:public Car
{private:
        Wheel wheel[4];
    public:
        RedCar(){cout<<"Construct a red car\n";}
};