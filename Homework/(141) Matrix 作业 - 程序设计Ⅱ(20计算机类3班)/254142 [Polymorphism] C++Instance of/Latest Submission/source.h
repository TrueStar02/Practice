#include<typeinfo>
#include<iostream>
using namespace std;
class Object{
    public:
    int i;
    Object(int n=0):i(n){}
    };

class Animal:public Object{public:Animal(int n=1):Object(n){}};
class Dog:public Animal {public:Dog(int n=2):Animal(n){}};
class Cat:public Animal{public:Cat(int n=3):Animal(n){}};

class Vehicle:public Object{public:Vehicle(int n=4):Object(n){}};
class Bus:public Vehicle{public:Bus(int n=5):Vehicle(n){}};
class Car:public Vehicle{public:Car(int n=6):Vehicle(n){}};

class Person:public Object{public:Person(int n=7):Object(n){}};
class Student:public Animal{public:Student(int n=8):Animal(n){}};
class Teacher:public Animal{public:Teacher(int n=9):Animal(n){}};
string instanceof(Object & obj)
{   switch(obj.i)
    {   case 0:return "Object";
        case 1:return "Animal";
        case 2:return "Dog";
        case 3:return "Cat";
        case 4:return "Vehicle";
        case 5:return "Bus";
        case 6:return "Car";
        case 7:return "Person";
        case 8:return "Student";
        case 9:return "Teacher";

    }
}