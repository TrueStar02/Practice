#ifndef TODO_H
#define TODO_H
#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
const double pi = acos(-1.0);
class point {
    private:
        double x, y;
    public:
        point();
        point(double, double);
        double getx() const;
        double gety() const;
        void print();
};
class vector1 : virtual public point {
    private:
        double dx, dy;
    public:
        vector1();
        vector1(double, double, double, double);
        double length();
        double getdx() const;
        double getdy() const;
        void print();
};
class circle : virtual public point {
    private:
        double r;
    public:
        circle();
        circle(double, double, double);
        double area();
        double getr() const;
        void print();
};
class todo : virtual public vector1, virtual public circle {
    public:
        todo();
        todo(double, double, double, double, double);
        void print();
};
#endif
